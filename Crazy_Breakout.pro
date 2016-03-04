#-------------------------------------------------
#
# Project created by QtCreator 2016-02-24T09:38:37
#
#-------------------------------------------------

QT       += core gui \
         multimedia \
         network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Crazy_Breakout
TEMPLATE = app


SOURCES += main.cpp\
        menuwindow.cpp \
    paddle.cpp \
    game.cpp \
    ball.cpp \
    block.cpp \
    score.cpp \
    health.cpp \
    Server.cpp \
    Thread.cpp

HEADERS  += menuwindow.h \
    paddle.h \
    game.h \
    ball.h \
    block.h \
    score.h \
    health.h \
    Server.h \
    Thread.h

FORMS    += menuwindow.ui

RESOURCES += \
    res.qrc
