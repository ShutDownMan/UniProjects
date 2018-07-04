TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    transaction.cpp \
    bank.cpp \
    account.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    transaction.h \
    bank.h \
    account.h

