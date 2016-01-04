#include "finance.h"
#include "ui_finance.h"
#include "QDate"

#include "QSqlError"
#include "QMessageBox"

#include "QAbstractItemDelegate"


Finance::Finance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Finance)
{
    ui->setupUi(this);


    row=0;
    child_row =0;
    today_sum_expand = 0;
    today_sum_income = 0;
    sum = 0;
    model1 = new QStandardItemModel(this);
    model2 = new QStandardItemModel(this);


    query =new QSqlQuery;
    ui->treeView_2->setHeaderHidden(true);
    ui->treeView->setHeaderHidden(true);


    set_mode(1);    //参数为1时，添加tree1，为2时添加tree2的model；
    set_mode(2);

    init();
}

Finance::~Finance()
{
    delete query;
    delete ui;
}

QString Finance::get_Datail(){
    if(ui->tabWidget->currentIndex()==0)
    return ui->lineEdit_4->text();
    else
        return ui->lineEdit->text();
}
float Finance::get_Account(){
    if(ui->tabWidget->currentIndex()==0)
    return ui->lineEdit_5->text().toFloat();
    else
        return ui->lineEdit_2->text().toFloat();
}
QString Finance::get_dater(){
    return QDate::currentDate().toString("yyyy-MM-dd");
}
void Finance::save_sli( ){                 //包含插入数据库与展示
    query->clear();
    QString sql;
    if(ui->tabWidget->currentIndex()==0){

         sql = "insert into income(Detail,Account,dater) values (?,?,?)";

}

    else{

         sql ="insert into expand(Detail,Account,dater) values (?,?,?)";

    }

    query->prepare(sql);
    query->addBindValue(get_Datail());
    query->addBindValue(get_Account());
    query->addBindValue(get_dater());
    if(query->exec()){
        emit send_status("operate succeed");

    }
    else{
        emit send_status("Operate failed");

    }

}

void Finance::check(QTreeView *tree){

    query->clear();
    QString sql;

    if(tree==ui->treeView_2)
      sql = QString("select dater from income where dater = '%1'").arg(get_dater());
    else
      sql = QString("select dater from expand where dater = '%1'").arg(get_dater());
    query->exec(sql);
    query->next();
    if (query->value(0)== get_dater()){
        checked = false;
    }
    else
        checked = true;

}

void Finance::updata_tree(QTreeView *tree, QStandardItemModel *model,int x){


    QStandardItem *parentItem = model->invisibleRootItem();

    int a;
    if(checked){

       a=x;
        QStandardItem *item = new QStandardItem(get_dater());

        model->setItem(a,item);
        parentItem = item;
        if(ui->treeView_2 == tree){
            row++;
        }
        else
        {
            child_row++;
        }
      }
    else
    {
        a= x-1;

         parentItem =  model->item(a);
    }


    QString g_detail = get_Datail();
    QString g_account = QString::number(get_Account());
    QStandardItem *item1 = new QStandardItem(g_detail + ":"+g_account +"$");
    parentItem->appendRow(item1);
    tree->setModel(model);
    tree->expand(model->item(a)->index());

}

void Finance::set_mode(int a){
    QSqlQuery *g_query =new QSqlQuery;
    QStandardItemModel *model = new QStandardItemModel(this);
    int x = 0;

    if(a==1)
    g_query->exec("select dater from income group by dater");
    else
    g_query->exec("select dater from expand group by dater");
    while(g_query->next()){
        QString g_dater = g_query->value(0).toString();

        QStandardItem *parentItem = model->invisibleRootItem();
        QStandardItem *item = new QStandardItem(g_dater);
        parentItem = item;
        model->setItem(x,item);
        query->clear();
        QString sql;
        if(a==1)
            sql = QString("select * from income where dater = '%1'").arg(g_dater);
        else
            sql = QString("select * from expand where dater = '%1'").arg(g_dater);
        query->exec(sql);
        while(query->next()){
            QString g_detail = query->value(0).toString();
            QString g_account = query->value(1).toString();
            QStandardItem *item1 = new QStandardItem(g_detail + ":"+g_account +"$");
            parentItem->appendRow(item1);

        }

        x++;


    }
    if(a==1)
    {
        model1 = model;
        ui->treeView_2->setModel(model1);
        row =x;
     //   ui->treeView_2->expand(model1->item(row-1)->index());

   }
    else{
         model2 = model;
         ui->treeView->setModel(model2);
         child_row =x;
    //      ui->treeView->expand(model2->item(row-1)->index());

    }


}

void Finance::on_commandLinkButton_2_clicked()
{
    check(ui->treeView_2);
    save_sli();
    updata_tree(ui->treeView_2,model1,row);
    sum = sum + get_Account();
    today_sum_income = today_sum_income + get_Account();
    set_sum_display(sum,today_sum_income,today_sum_expand);
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

}



void Finance::on_commandLinkButton_clicked()
{
    check(ui->treeView);
    save_sli();
    updata_tree(ui->treeView,model2,child_row);
    sum = sum - get_Account();
    today_sum_expand = today_sum_expand + get_Account();
    set_sum_display(sum,today_sum_income,today_sum_expand);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void Finance::set_sum_display(float a, float b, float c){

    ui->lineEdit_3->setText(QString::number(c));
    ui->lineEdit_6->setText(QString::number(b));
    ui->lcdNumber->display(a );
}
void Finance::init(){
    QString sql;
    query->clear();
     sql = QString("select Account from income where dater = '%1' group by dater").arg(get_dater());
    query->exec(sql);
    query->next();
    today_sum_income = query->value(0).toFloat();

    query->clear();
     sql = QString("select Account from expand where dater = '%1' group by dater").arg(get_dater());
    query->exec(sql);
    query->next();
    today_sum_expand = query->value(0).toFloat();

    query->clear();
    query->exec("select SUM(Account) as SUM from income ");
    query->next();


    sum = query->value(0).toFloat();

    query->clear();
    query->exec("select SUM(Account) as SUM from expand ");
    query->next();


    sum = sum - query->value(0).toFloat();

    set_sum_display(sum,today_sum_income,today_sum_expand);

}
