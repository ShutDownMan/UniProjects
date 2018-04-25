TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ListStructured.h \
    ListOO.h

