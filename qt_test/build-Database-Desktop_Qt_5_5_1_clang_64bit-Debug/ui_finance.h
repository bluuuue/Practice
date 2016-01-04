/********************************************************************************
** Form generated from reading UI file 'finance.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINANCE_H
#define UI_FINANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finance
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QCommandLinkButton *commandLinkButton_2;
    QTreeView *treeView_2;
    QWidget *tab_2;
    QCommandLinkButton *commandLinkButton;
    QTreeView *treeView;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *Finance)
    {
        if (Finance->objectName().isEmpty())
            Finance->setObjectName(QStringLiteral("Finance"));
        Finance->resize(538, 413);
        horizontalLayout = new QHBoxLayout(Finance);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(Finance);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("color:rgb(0, 85, 255);\n"
"background-color:rgb(255, 255, 255)"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);

        horizontalLayout_2->addWidget(label_8);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_2->addWidget(lcdNumber);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QLatin1String("color:rgb(0, 85, 255);\n"
";"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideLeft);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 135, 152));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_3->addWidget(lineEdit_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_3->addWidget(label_6);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout_3->addWidget(lineEdit_5);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        verticalLayout_3->addWidget(lineEdit_6);

        commandLinkButton_2 = new QCommandLinkButton(tab);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(160, 100, 31, 41));
        treeView_2 = new QTreeView(tab);
        treeView_2->setObjectName(QStringLiteral("treeView_2"));
        treeView_2->setGeometry(QRect(210, 10, 271, 301));
        treeView_2->setStyleSheet(QLatin1String("color:rgb(0, 85, 255);\n"
"background:url(:/Image/sun.png)"));
        tabWidget->addTab(tab, QString());
        treeView_2->raise();
        layoutWidget->raise();
        commandLinkButton_2->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        commandLinkButton = new QCommandLinkButton(tab_2);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(160, 100, 31, 41));
        treeView = new QTreeView(tab_2);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(210, 10, 271, 301));
        treeView->setStyleSheet(QLatin1String("color:rgb(0, 85, 255);\n"
"background:url(:/Image/rain.png)"));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 70, 135, 152));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout->addWidget(widget);


        retranslateUi(Finance);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Finance);
    } // setupUi

    void retranslateUi(QWidget *Finance)
    {
        Finance->setWindowTitle(QApplication::translate("Finance", "Form", 0));
        label_8->setText(QApplication::translate("Finance", "\346\210\221\347\232\204\351\222\261\357\274\201\357\274\201\357\274\201\357\274\201\350\277\231\346\230\257\346\210\221\347\232\204\351\222\261\357\274\201\357\274\201\357\274\201\357\274\201\357\274\201\357\274\201", 0));
        label->setText(QApplication::translate("Finance", "Private Savings:", 0));
        label_5->setText(QApplication::translate("Finance", "Detail:", 0));
        label_6->setText(QApplication::translate("Finance", "Account:", 0));
        label_7->setText(QApplication::translate("Finance", "Today_Sum:", 0));
        commandLinkButton_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Finance", "Income", 0));
        commandLinkButton->setText(QString());
        label_2->setText(QApplication::translate("Finance", "Detail:", 0));
        label_3->setText(QApplication::translate("Finance", "Account:", 0));
        label_4->setText(QApplication::translate("Finance", "Today_Sum:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Finance", "expend", 0));
    } // retranslateUi

};

namespace Ui {
    class Finance: public Ui_Finance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCE_H
