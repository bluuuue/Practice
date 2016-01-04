#include "inputcontextdialog.h"
#include "ui_inputcontextdialog.h"
#include "QMessageBox"
#include "QFile"
#include <QTextStream>
#include "QTextCodec"




InputContextDialog::InputContextDialog(QWidget *parent,const QString &fileName):
    QDialog(parent),
    ui(new Ui::InputContextDialog)

{
    m_fileName = "journal/" +fileName +".txt";

    ui->setupUi(this);

    this->setModal(true);


}

InputContextDialog::~InputContextDialog()
{

    delete ui;

}

void InputContextDialog::on_pushButton_clicked()
{
    this->close();
}
void InputContextDialog::loadFile()
{
    QFile file(m_fileName);
    if (!file.exists()) {
        return;
    }
    if (file.open(QIODevice::ReadWrite)) {
//        QTextStream out(&file);
//        ui->textEdit->setText(out.readAll());
//        file.close();
        QByteArray data=file.readAll ();             //可以实现中文读取
        ui->textEdit->setText (QObject::tr(data));
        setWindowTitle (m_fileName);
    }
}
