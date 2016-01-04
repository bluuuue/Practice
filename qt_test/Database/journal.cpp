
#include "journal.h"
#include "ui_journal.h"
#include "QPalette"
#include "QDate"

#include "QTextCodec"
#include "QFile"
#include "QMessageBox"
#include <QTextStream>



Journal::Journal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Journal)
{
    ui->setupUi(this);

    //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8")); //文本格式设置
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));

    P_query = new QSqlQuery;
    ui->dateEdit->setDate(QDate::currentDate());
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Date")<<tr("Title"));
    //ui->tableWidget->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
    //ui->tableWidget->horizontalHeader()->setResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    set_mode();



}

Journal::~Journal()
{
    delete P_query;
    delete ui;
}
QString Journal::CreateAFilename()
{
    return  "journal/"+ui->dateEdit->date().toString("yyyyMMdd")+".txt";
}
QString Journal::get_title()
{

    return  M_Filename = ui->lineEdit->text();

}
QString Journal::get_Date()
{
    return M_Date = ui->dateEdit->date().toString("yyyyMMdd");
}
QString Journal::get_weather()
{
    return M_weather = ui->comboBox->currentText();
}
void Journal::Save_file()
{
    QFile file(CreateAFilename());
    if (file.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        in << "weather:" << get_weather();
        in << endl;
        in <<"Date:" << get_Date();
        in << endl;
        in <<"title:" << get_title() ;
        in << endl;
        in << ui->textEdit->toPlainText();
        file.close();

    } else {
        QMessageBox::critical(this,tr("fail"),tr("Save file failed"));
    }
}
void Journal::sli_save()
{
    P_query->clear();
    P_query->prepare("insert into journal(title,write_date)"
                     "values(?,?)");
    P_query->addBindValue(get_title());
    P_query->addBindValue(get_Date());
    if (!P_query->exec()) {
         QMessageBox::critical(this,tr("Repeat"),tr("You have written diary today, do you remember?"));
        //ui->textEdit->textCursor().insertText(P_query->lastError().text());
    }
    else

    {
        emit send_status("Save the new diary");
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(get_Date()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(get_title()));

    }

}
void Journal::clearAllItems(QTableWidget *pw)
{
    int counter = pw->rowCount();
    while(counter)
    {
        counter = counter - 1;
        pw->removeRow(counter);
    }
}
void Journal::set_mode()
{
    P_query->clear();
    P_query->exec("select * from journal");
    if (P_query == NULL) {

    } else {
        clearAllItems(ui->tableWidget);
        while (P_query->next()) {
            QString title = P_query->value(0).toString();
            QString date = P_query->value(1).toString();

            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(date));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(title));
            ui->tableWidget->selectRow(row);

        }
    }


}
void Journal::on_pushButton_3_clicked()
{

      sli_save();
      Save_file();
      ui->tabWidget->setCurrentIndex(1);

}
void Journal::delete_sli(int row)
{
    P_query->clear();

    QString date = ui->tableWidget->takeItem(row,0)->text();

    QString sql = QString("delete from journal where write_date = '%1'").arg(date);
    if (!P_query->exec(sql)) {
        emit send_status("delete diary failed");
    }
    else
    {
        emit send_status("delete diary succeed");
        ui->tableWidget->removeRow(row);
        if(row>=1)
        ui->tableWidget->selectRow(row-1);

    }
    QFile file("journal/"+date+".txt");
    file.remove();

}
void Journal::on_pushButton_clicked()
{
    delete_sli(ui->tableWidget->currentRow());
}

void Journal::on_pushButton_2_clicked()
{
    int row=ui->tableWidget->currentRow();
    InputContextDialog dialog(this,ui->tableWidget->item(row,0)->text());
    dialog.loadFile();
    dialog.show();
    dialog.exec();
}
