TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    base.h

