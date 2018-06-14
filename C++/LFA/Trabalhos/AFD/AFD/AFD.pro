TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    automata.cpp \
    state.cpp

include(deployment.pri)
qtcAddDeployment()

DISTFILES += \
    automata.txt

HEADERS += \
    automata.h \
    state.h

