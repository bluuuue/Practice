/********************************************************************************
** Form generated from reading UI file 'journal.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNAL_H
#define UI_JOURNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Journal
{
public:
    QHBoxLayout *horizontalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_5;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Journal)
    {
        if (Journal->objectName().isEmpty())
            Journal->setObjectName(QStringLiteral("Journal"));
        Journal->resize(553, 443);
        horizontalLayout_6 = new QHBoxLayout(Journal);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        tabWidget = new QTabWidget(Journal);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(428, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_3->addWidget(tableWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_6->addWidget(tabWidget);


        retranslateUi(Journal);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Journal);
    } // setupUi

    void retranslateUi(QWidget *Journal)
    {
        Journal->setWindowTitle(QApplication::translate("Journal", "Form", 0));
        label->setText(QApplication::translate("Journal", "Weather\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Journal", "\346\231\264", 0)
         << QApplication::translate("Journal", "\351\233\250\345\244\251", 0)
         << QApplication::translate("Journal", "\351\230\264\345\244\251", 0)
         << QApplication::translate("Journal", "\351\233\250\351\233\252", 0)
         << QApplication::translate("Journal", "\345\244\247\351\233\252", 0)
        );
        label_2->setText(QApplication::translate("Journal", "Date\357\274\232", 0));
        label_3->setText(QApplication::translate("Journal", "Title\357\274\232", 0));
        pushButton_3->setText(QApplication::translate("Journal", "Save", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Journal", "New Journal", 0));
        pushButton->setText(QApplication::translate("Journal", "Delete", 0));
        pushButton_2->setText(QApplication::translate("Journal", "Details", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Journal", "Manage", 0));
    } // retranslateUi

};

namespace Ui {
    class Journal: public Ui_Journal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNAL_H
