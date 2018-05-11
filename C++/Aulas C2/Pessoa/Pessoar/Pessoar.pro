TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pessoa.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pessoa.h

