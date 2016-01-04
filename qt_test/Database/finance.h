#ifndef FINANCE_H
#define FINANCE_H

#include "QSqlQuery"
#include <QWidget>
#include "QStandardItemModel"
#include "QAbstractItemModel"
#include "QTreeView"

namespace Ui {
class Finance;
}

class Finance : public QWidget
{
    Q_OBJECT
    
public:
    explicit Finance(QWidget *parent = 0);
    ~Finance();
signals:
    void send_status(QString);
private slots:
    void on_commandLinkButton_2_clicked();



    void on_commandLinkButton_clicked();

private:
    Ui::Finance *ui;

    QSqlQuery *query;
    QString get_Datail();
    float get_Account();
    QString get_dater();

    QString Datail;
    QString Account;
    QString Dater;
    float today_sum_income;
    float today_sum_expand;
    float sum;

    QStandardItemModel *model1;
    QStandardItemModel *model2;

    void  check(QTreeView *tree);
    bool  checked;

    int row;
    int child_row;

    void save_sli();
    void delete_sli();
    void init();
    void set_sum_display(float , float, float);

    void set_mode(int);

    void updata_tree(QTreeView *tree, QStandardItemModel *model, int a);


};

#endif // FINANCE_H
