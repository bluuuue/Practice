#ifndef CONTACTS_H
#define CONTACTS_H

#include <QWidget>
#include "QSqlQuery"
#include "QTableWidget"

namespace Ui {
class Contacts;
}

class Contacts : public QWidget
{
    Q_OBJECT
    
public:
    explicit Contacts(QWidget *parent = 0);
    ~Contacts();
    QString get_Name();
    QString get_Phonenum();
    QString get_site();
    QString get_brithday();

    QSqlQuery *query;

signals:
    void send_status(QString);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_commandLinkButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Contacts *ui;


    void add_sli();
 //   void add_finish();


    void delete_sli();
    void select_sli();
    void update_sli();
    void look_for();

    void clearAllItems(QTableWidget *pw);
    void set_mode();

    QString Name;
    QString Num;
    QString Site;
    QString Birthday;




};

#endif // CONTACTS_H
