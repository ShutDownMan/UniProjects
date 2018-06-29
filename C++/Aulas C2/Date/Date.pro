TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    date.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    date.h

