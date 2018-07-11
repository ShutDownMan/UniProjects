TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    polygon.cpp \
    circle.cpp \
    complexpolygon.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    polygon.h \
    circle.h \
    complexpolygon.h

