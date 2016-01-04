#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "journal.h"
#include "contacts.h"
#include "sign_in.h"
#include "finance.h"


class Journal;
class Contacts;
class Sign_in;
class Finance;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_listWidget_currentRowChanged(int currentRow);
    void set_statusbar(QString);

private:
    Ui::MainWindow *ui;

    void InitUi();

    Journal *P_Journal;
    Contacts *P_Contacts;
    Sign_in *P_Sign_in;
    Finance *P_Finance;

};

#endif // MAINWINDOW_H
