#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QtSql/QSqlError>

bool createConnection()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setDatabaseName("music.db");
  //告知数据库的用户名和密码
  db.setUserName("root");
  db.setPassword("root");
  if(!db.open())
  {
    QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
    return false;
  }

  return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    std::cout << "ads" << std::endl;
    w.show();

    return a.exec();
}
