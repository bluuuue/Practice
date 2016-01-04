#ifndef DATABASE_H
#define DATABASE_H

#include "QSqlDatabase"
#include "QSqlQuery"
#include "QMessageBox"
#include "QSqlError"


static bool Create_Databse(const QString &fileName){
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");  //添加sqlite数据库
    db.setDatabaseName(fileName);

    if(!db.open()){
        QMessageBox::critical(0,qApp->tr("Cannot open database"),
                              qApp->tr("Cannot create a sqlite database.\n\n"
                                       "Click Cancel to exit."));
        return false;
    }

    QSqlQuery query;  // 执行sql语句
    query.exec("create table journal(title varchar(30) , write_date char(10) primary key)");

    query.exec("create table contact(Name char(20) primary key,phone_code char(15),birthday date,site char(80))");

    query.exec("create table income (Detail char(50),Account float,dater date)");

    query.exec("create table expand (Detail char(50),Account float,dater date)");

    query.exec("create table sign(goal varchar,sum int ,current int,goalset bool)");

    return true;


}


#endif // DATABASE_H


