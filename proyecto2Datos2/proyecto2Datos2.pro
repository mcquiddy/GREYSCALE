#-------------------------------------------------
#
# Project created by QtCreator 2015-10-20T11:32:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto2Datos2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gui.cpp

HEADERS  += mainwindow.h \
    Constants.h \
    gui.h \
    linked_list.h \
    Node.h

FORMS    += mainwindow.ui

RESOURCES += \
    rec.qrc
