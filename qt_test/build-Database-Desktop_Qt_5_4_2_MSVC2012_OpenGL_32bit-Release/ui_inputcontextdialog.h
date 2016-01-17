/********************************************************************************
** Form generated from reading UI file 'inputcontextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTCONTEXTDIALOG_H
#define UI_INPUTCONTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InputContextDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *InputContextDialog)
    {
        if (InputContextDialog->objectName().isEmpty())
            InputContextDialog->setObjectName(QStringLiteral("InputContextDialog"));
        InputContextDialog->resize(462, 378);
        verticalLayout = new QVBoxLayout(InputContextDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(InputContextDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        textEdit->setFont(font);
        textEdit->setStyleSheet(QStringLiteral("color:rgb(0, 85, 255)"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(InputContextDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(InputContextDialog);

        QMetaObject::connectSlotsByName(InputContextDialog);
    } // setupUi

    void retranslateUi(QDialog *InputContextDialog)
    {
        InputContextDialog->setWindowTitle(QApplication::translate("InputContextDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("InputContextDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class InputContextDialog: public Ui_InputContextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTCONTEXTDIALOG_H
