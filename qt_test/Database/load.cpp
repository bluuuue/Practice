#include "load.h"
#include "ui_load.h"

load::load(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::load)
{
    ui->setupUi(this);
    setWindowFlags(Qt::SplashScreen);
}

load::~load()
{
    delete ui;
}
