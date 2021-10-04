#-------------------------------------------------
#
# Project created by QtCreator 2021-09-25T15:39:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_task
TEMPLATE = app
CONFIG += c++11


SOURCES += \
    main.cpp \
    songdialog.cpp \
    songlistdialog.cpp \
    data_song.cpp \
    model_song.cpp

HEADERS  += \
    songdialog.h \
    songlistdialog.h \
    data_song.h \
    model_song.h

FORMS    += \
    songdialog.ui \
    songlistdialog.ui
