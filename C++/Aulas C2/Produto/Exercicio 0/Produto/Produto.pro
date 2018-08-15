TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    chemical.cpp \
    product.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    chemical.h \
    product.h

