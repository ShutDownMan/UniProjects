TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    node.tcc \
    heap.tcc \
    queue.tcc

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    node.h \
    heap.h \
    queue.h

