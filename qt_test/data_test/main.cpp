#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QtSql>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //std::cout << "ads" << std::endl;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //添加数据库驱动
    //QString filename = QFileDialog::getOpenFileName(this, tr("data.db"), true);
    db.setDatabaseName("data.db"); //数据库连接命名
    if(!db.open()) //打开数据库
    {
        return false;
    }

    QSqlQuery query; //以下执行相关QSL语句
    /*
    query.exec("create table students(id int primary key,name varchar)");
    query.exec();
    //新建student表，id设置为主键，还有一个name项
    query.exec("insert into students values(1,'xiaogang')");
    query.exec();
    query.exec("insert into students values(4,'xiaoling')");
    query.exec();
    query.exec("insert into students values(3,'xiaohong')");
    query.exec();
    //向表中插入3条记录
    */
    query.exec("select id,name from students where id >= 2");
    //查找表中id >=2 的记录的id项和name项的值
    while(query.next())       //query.next()指向查找到的第一条记录，然后每次后移一条记录
    {
        int ele0 = query.value(0).toInt();        //query.value(0)是id的值，将其转换为int型
        QString ele1 =query.value(1).toString();
        qDebug() << ele0 <<ele1 ;      //输出两个值
    }


    w.show();

    return a.exec();
}
