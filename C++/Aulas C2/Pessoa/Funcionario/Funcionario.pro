TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pessoa.cpp \
    funcionario.cpp

HEADERS += \
    pessoa.h \
    funcionario.h

DISTFILES += \
    Funcionario.pro.user
