#ifndef JOURNAL_H
#define JOURNAL_H

#include <QWidget>
#include "inputcontextdialog.h"
#include <QSqlQuery>
#include "QTableWidget"
#include "QSqlError"


namespace Ui {
class Journal;
}

class Journal : public QWidget
{
    Q_OBJECT
    
public:
    explicit Journal(QWidget *parent = 0);
    ~Journal();
    QString get_title();
    QString get_Date();
    QString get_weather();


    QString CreateAFilename();
signals:
    void send_status(QString);
    
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Journal *ui;
    QString M_Filename;
    QString M_Date;
    QString M_weather;
    QSqlQuery *P_query;

    InputContextDialog Dialog;


    void Save_file();
    void sli_save();
    void set_mode();
    void clearAllItems(QTableWidget *pw);
    void delete_sli(int row );
    void delete_file(int row);



};

#endif // JOURNAL_H
