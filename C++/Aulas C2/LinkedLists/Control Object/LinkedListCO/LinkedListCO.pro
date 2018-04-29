TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    node.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    node.h

