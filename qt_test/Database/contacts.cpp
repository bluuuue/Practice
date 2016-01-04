#include "contacts.h"
#include "ui_contacts.h"
#include "QSqlError"

#include "QMessageBox"

Contacts::Contacts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Contacts)
{
    ui->setupUi(this);
    ui->pushButton_3->setEnabled(false);
    query = new QSqlQuery();


    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Name")<<tr("Phonenumber")<<tr("Birthday")<<tr("Site"));
    //ui->tableWidget->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
    //ui->tableWidget->horizontalHeader()->setResizeMode(1,QHeaderView::Stretch);
    //ui->tableWidget->horizontalHeader()->setResizeMode(2,QHeaderView::Stretch);
    //ui->tableWidget->horizontalHeader()->setResizeMode(3,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    set_mode();


}

Contacts::~Contacts()
{
    delete query;
    delete ui;
}

void Contacts::set_mode()
{
    query->clear();
    query->exec("select * from contact");
    while (query->next()) {
        QString Name = query->value(0).toString();
        QString Phonenumber = query->value(1).toString();
        QString Birthday = query->value(2).toString();
        QString Site = query->value(3).toString();

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(Name));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(Phonenumber));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(Birthday));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(Site));
        ui->tableWidget->selectRow(0);
    }

}
QString Contacts::get_Name()
{
    return ui->lineEdit_2->text();
}
QString Contacts::get_Phonenum()
{
    return ui->lineEdit_3->text();
}
QString Contacts::get_site(){
    return ui->textEdit->toPlainText();
}
QString Contacts::get_brithday(){
    return ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
}
void Contacts::add_sli(){
    query->clear();
    query->prepare("insert into contact(Name,phone_code,birthday,site)"
                   "values(?,?,?,?)");
    Name = get_Name();
    Num =get_Phonenum();
    Site = get_site();
    Birthday =get_brithday();
    query->addBindValue(get_Name());
    query->addBindValue(get_Phonenum());
    query->addBindValue(get_brithday());
    query->addBindValue(get_site());
    if(!query->exec()){


        emit send_status("save new linkman fail");
        QMessageBox::warning(0,tr("NOTE"),tr("This linkman already exists,"));
    }
    else{
        emit send_status("save new linkman" +Name+ "success");
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->textEdit->clear();
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(Name));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(Num));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(Birthday));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(Site));
        ui->tableWidget->selectRow(row);
    }
}

void Contacts::on_pushButton_2_clicked()
{
    add_sli();
}
void Contacts::delete_sli(){
    query->clear();
    int row=ui->tableWidget->currentRow();

    QString delete_Name = ui->tableWidget->takeItem(row,0)->text();
    QString sql = QString("delete from contact where Name= '%1'").arg(delete_Name);
    if(query->exec(sql))
    {
        emit send_status("delete success");
        ui->tableWidget->removeRow(row);
        if(row>=1)
        ui->tableWidget->selectRow(row-1);

    }
    else
    {
        emit send_status("delete fail");
    }



}

void Contacts::on_pushButton_clicked()
{
    delete_sli();
}

void Contacts::clearAllItems(QTableWidget *pw)
{
    int counter = pw->rowCount();
    while(counter)
    {
        counter = counter - 1;
        pw->removeRow(counter);
    }
}
void Contacts::look_for(){
    query->clear();
    QString modifi_name = ui->lineEdit->text();
    QString sql = QString("select * from contact where Name like '%1'").arg(modifi_name+"%");
    query->exec(sql);

    clearAllItems(ui->tableWidget);
    while (query->next()) {
        QString Name = query->value(0).toString();
        QString Phonenumber = query->value(1).toString();
         QString Birthday = query->value(2).toString();
          QString Site = query->value(3).toString();

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(Name));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(Phonenumber));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(Birthday));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(Site));
        ui->tableWidget->selectRow(0);
    }



}

void Contacts::on_lineEdit_textChanged(const QString &arg1)
{
    look_for();

}

void Contacts::on_commandLinkButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->lineEdit_2->setEnabled(false);
    int row= ui->tableWidget->currentRow();
    ui->lineEdit_2->setText( ui->tableWidget->item(row,0)->text());    //takeItem使原本的值消失  使用item解决
    ui->lineEdit_3->setText(ui->tableWidget->item(row,1)->text());
    ui->textEdit->setText(ui->tableWidget->item(row,3)->text());
    ui->pushButton_3->setEnabled(true);



}

void Contacts::update_sli(){
    query->clear();
    QString sql =QString ("update contact set phone_code = ? ,site= ? where Name = '%1'").arg(ui->lineEdit_2->text());
    query->prepare(sql);
    query->addBindValue(ui->lineEdit_3->text());
    query->addBindValue(ui->textEdit->toPlainText());

    //赋值
    Name = get_Name();
    Num =get_Phonenum();
    Site =get_site();

    if(query->exec()){
        emit send_status("Update"+ ui->lineEdit_2->text()+ "success");
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->textEdit->clear();
        ui->lineEdit_2->setEnabled(true);
    }
    else{
        QMessageBox::warning(this,tr("warning"),tr("Update failed,please try to delete and rewrite this info"));

    }
}

void Contacts::on_pushButton_3_clicked()
{
    update_sli();
//    clearAllItems(ui->tableWidget);
//    set_mode();
    int row =ui->tableWidget->currentRow();
   // ui->tableWidget->setItem(row,0,new  QTableWidgetItem(ui->lineEdit_2->text()));
    ui->tableWidget->item(row,0)->setText(Name);
    ui->tableWidget->item(row,1)->setText(Num);
    ui->tableWidget->item(row,3)->setText(Site);
    ui->tableWidget->selectRow(row);
    ui->tabWidget->setCurrentIndex(0);
    ui->pushButton_3->setEnabled(false);

}
