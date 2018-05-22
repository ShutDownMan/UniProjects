TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    entry.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    entry.h

