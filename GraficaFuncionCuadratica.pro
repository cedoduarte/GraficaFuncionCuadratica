#-------------------------------------------------
#
# Project created by QtCreator 2016-03-19T12:49:20
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FuncionCuadratica
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    ParametrosForm.cpp \
    qcustomplot.cpp \
    DuPlot.cpp

HEADERS  += Widget.h \
    ParametrosForm.h \
    qcustomplot.h \
    DuPlot.h

FORMS    += Widget.ui \
    ParametrosForm.ui

QMAKE_CXXFLAGS += -std=gnu++14
