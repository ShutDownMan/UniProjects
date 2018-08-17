#-------------------------------------------------
#
# Project created by QtCreator 2018-08-09T13:37:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Agenda
TEMPLATE = app


SOURCES += main.cpp \
        view/mainwindow.cpp \
    utils/logger.cpp \
    view/viewconsultarpessoa.cpp

HEADERS  += view/mainwindow.h \
    utils/logger.h \
    view/viewconsultarpessoa.h

FORMS    += view/mainwindow.ui \
    view/viewconsultarpessoa.ui
