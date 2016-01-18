/********************************************************************************
** Form generated from reading UI file 'sign_in.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_H
#define UI_SIGN_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sign_in
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QProgressBar *progressBar;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QCheckBox *checkBox;
    QLabel *label_5;

    void setupUi(QWidget *Sign_in)
    {
        if (Sign_in->objectName().isEmpty())
            Sign_in->setObjectName(QStringLiteral("Sign_in"));
        Sign_in->resize(500, 397);
        horizontalLayout = new QHBoxLayout(Sign_in);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(Sign_in);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("color:rgb(85, 170, 0);\n"
"\n"
"background-color:rgb(255, 255, 255);"));
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 350, 461, 20));
        progressBar->setValue(24);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 40, 188, 27));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 280, 50, 50));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QLatin1String("QPushButton#pushButton{\n"
"border-image: url(:/Image/right_checked.png)\n"
"}\n"
"QPushButton#pushButton:pressed{\n"
"border-image: url(:/Image/click.png);\n"
"}"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 280, 50, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton#pushButton_2{\n"
"border-image:url(:/Image/fault_checked.png);\n"
"}\n"
"QPushButton#pushButton_2:pressed{\n"
"border-image:url(:/Image/click2.png);\n"
"}"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 40, 130, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_2->addWidget(lcdNumber);

        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 261, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);

        layoutWidget2 = new QWidget(widget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(280, 10, 191, 21));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        checkBox = new QCheckBox(layoutWidget2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        horizontalLayout_5->addWidget(checkBox);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 90, 281, 171));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/Image/normal.png")));
        label_5->setScaledContents(true);

        horizontalLayout->addWidget(widget);


        retranslateUi(Sign_in);

        QMetaObject::connectSlotsByName(Sign_in);
    } // setupUi

    void retranslateUi(QWidget *Sign_in)
    {
        Sign_in->setWindowTitle(QApplication::translate("Sign_in", "Form", 0));
        label_4->setText(QApplication::translate("Sign_in", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; color:#55aa00; vertical-align:super;\">Good habit form now\357\274\201</span></p></body></html>", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_3->setText(QApplication::translate("Sign_in", "Current\357\274\232", 0));
        label->setText(QApplication::translate("Sign_in", "Goal:", 0));
        label_2->setText(QApplication::translate("Sign_in", "sum\357\274\232", 0));
        label_6->setText(QApplication::translate("Sign_in", "\345\244\251", 0));
        checkBox->setText(QApplication::translate("Sign_in", "Set", 0));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Sign_in: public Ui_Sign_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_H
