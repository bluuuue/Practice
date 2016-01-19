#include <QApplication>
#include "mainwindow.h"
#include "Database.h"
#include <QPixmap>
#include <QSplashScreen>
#include <QtTest>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/Image/load.png");
    QSplashScreen splash(pixmap);
    splash.show();
    QTest::qWait(3000);
    if(!Create_Databse("mydb.mdb"))
    {
        return -1;
    }

   MainWindow w;

    w.show();
    splash.finish(&w);
    
    return a.exec();
}
