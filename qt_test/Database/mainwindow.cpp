#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitUi();
    ui->listWidget->setCurrentRow(0);
    connect(P_Contacts,SIGNAL(send_status(QString)),this,SLOT(set_statusbar(QString)));
    connect(P_Finance,SIGNAL(send_status(QString)),this,SLOT(set_statusbar(QString)));
    connect(P_Sign_in,SIGNAL(send_status(QString)),this,SLOT(set_statusbar(QString)));
    connect(P_Journal,SIGNAL(send_status(QString)),this,SLOT(set_statusbar(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitUi()
{
    P_Journal = new Journal(this);
    P_Contacts = new Contacts(this);
    P_Sign_in = new Sign_in(this);
    P_Finance = new Finance(this);

    ui->stackedWidget->addWidget(P_Journal);
    ui->stackedWidget->addWidget(P_Contacts);
    ui->stackedWidget->addWidget(P_Finance);
    ui->stackedWidget->addWidget(P_Sign_in);

}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}

void MainWindow::set_statusbar(QString a){
    ui->statusBar->showMessage(a,2000);
}
















