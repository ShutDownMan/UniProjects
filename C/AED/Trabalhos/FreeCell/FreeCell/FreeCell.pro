TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.c \
    heap.c \
    stringmanipulation.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    heap.h \
    stringmanipulation.h

