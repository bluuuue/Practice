#-------------------------------------------------
#
# Project created by QtCreator 2014-05-07T08:23:30
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Database
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    journal.cpp \
    finance.cpp \
    contacts.cpp \
    sign_in.cpp \
    inputcontextdialog.cpp

HEADERS  += mainwindow.h \
    journal.h \
    finance.h \
    contacts.h \
    sign_in.h \
    Database.h \
    inputcontextdialog.h

FORMS    += mainwindow.ui \
    journal.ui \
    finance.ui \
    contacts.ui \
    sign_in.ui \
    inputcontextdialog.ui

RESOURCES += \
    image.qrc

CONFIG += shared  release

QT += testlib

RC_FILE = icon.rc
