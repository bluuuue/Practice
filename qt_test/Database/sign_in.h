#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QWidget>
#include "QSqlQuery"
#include "QSqlError"


namespace Ui {
class Sign_in;
}

class Sign_in : public QWidget
{
    Q_OBJECT
    
public:
    explicit Sign_in(QWidget *parent = 0);
    ~Sign_in();

signals:
    void send_status(QString);
private slots:
    void on_checkBox_toggled(bool checked);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Sign_in *ui;
    QString get_goal();
    int get_sum();
    int get_current();
    int current;
    bool set;

    void save_sli();
    void display();
    void update();

    QSqlQuery *query;

    void progressBar_display(int range,int value);


};

#endif // SIGN_IN_H
