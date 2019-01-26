#-------------------------------------------------
#
# Project created by QtCreator 2016-06-04T16:03:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Logger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    LoggingCategories.cpp

HEADERS  += mainwindow.h \
    LoggingCategories.h

FORMS    += mainwindow.ui
