#include "sign_in.h"
#include "ui_sign_in.h"
#include "QTextCodec"
#include "QPixmap"

Sign_in::Sign_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign_in)
{
    ui->setupUi(this);

    query = new QSqlQuery;
    display();
}

Sign_in::~Sign_in()
{
    delete query;
    delete ui;
}

void Sign_in::on_checkBox_toggled(bool checked)
{
    set = checked;
    if(checked == true)
    {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        save_sli();

    }
    else{
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->lcdNumber->display(0);
    }

}
QString Sign_in::get_goal(){
    return ui->lineEdit->text();
}
int Sign_in::get_sum(){
    return ui->lineEdit_2->text().toInt();
}
int Sign_in::get_current(){
    return ui->lcdNumber->value();
}

void Sign_in::save_sli()
{
    query->clear();
    query->prepare("update sign set goal = ?,sum =?,current = ?,goalset = ?");
    query->addBindValue(get_goal());
    query->addBindValue(get_sum());
    query->addBindValue(get_current());
    query->addBindValue(set);
    if(query->exec()){
        emit send_status("Set new goals");
        progressBar_display(get_sum(),get_current());
    }
    else
    {
        emit send_status("The new goal setting failure");
    }

}
void Sign_in::display(){
    query->clear();
    query->exec("select * from sign");
    query->next();
    ui->lineEdit->setText(query->value(0).toString());
    ui->lineEdit_2->setText(query->value(1).toString());
    ui->lcdNumber->display(query->value(2).toInt());
    ui->checkBox->setChecked(query->value(3).toBool());
    progressBar_display(get_sum(),get_current());

}
void Sign_in::update(){
    query->clear();
    query->prepare("update sign set current =?");
    query->addBindValue(get_current());
    if(query->exec()){
        emit send_status("Sign in successfully");
    }

}

void Sign_in::on_pushButton_clicked()
{
    ui->lcdNumber->display(get_current()+1);
    //ui->graphicsView->showFullScreen();
    update();
    QPixmap pixmap(":/Image/goodjob.png");
    ui->label_5->setPixmap(pixmap);
    ui->label_5->show();
    ui->progressBar->setValue(get_current());
}

void Sign_in::on_pushButton_2_clicked()
{
    QPixmap pixmap(":/Image/anoyed.png");
    ui->label_5->setPixmap(pixmap);
    ui->label_5->show();
}
void Sign_in::progressBar_display(int range, int value){
    ui->progressBar->setRange(0,range);
    ui->progressBar->setValue(value);


}
