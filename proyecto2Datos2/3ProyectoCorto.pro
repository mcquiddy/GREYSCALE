#-------------------------------------------------
#
# Project created by QtCreator 2015-10-28T13:35:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3ProyectoCorto
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp

HEADERS  += mainwindow.h \
    Constants.h \
    linked_list.h \
    Node.h \
    image.h

FORMS    += mainwindow.ui
