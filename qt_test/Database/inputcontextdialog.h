#ifndef INPUTCONTEXTDIALOG_H
#define INPUTCONTEXTDIALOG_H

#include <QDialog>




namespace Ui {
class InputContextDialog;
}

class InputContextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputContextDialog(QWidget *parent = 0,const QString &fileName= QString());
    ~InputContextDialog();
void loadFile();
private slots:
    void on_pushButton_clicked();

private:
    Ui::InputContextDialog *ui;
    QString m_fileName;



};

#endif // INPUTCONTEXTDIALOG_H
