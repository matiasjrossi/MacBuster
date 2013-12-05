#-------------------------------------------------
#
# Project created by QtCreator 2013-03-20T21:00:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MacBuster
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glviewport.cpp

HEADERS  += mainwindow.h \
    glviewport.h

FORMS    += mainwindow.ui



QT += opengl

mac: LIBS += -framework GLUT
