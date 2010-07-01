# -------------------------------------------------
# Project created by QtCreator 2010-05-14T22:37:29
# -------------------------------------------------
QT += sql
QT += webkit
TARGET = ../Dair_Talk.bin
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    databaseclass.cpp \
    talkw.cpp \
    popup.cpp
HEADERS += mainwindow.h \
    databaseclass.h \
    talkw.h \
    popup.h
FORMS += mainwindow.ui \
    talkw.ui \
    popup.ui
RESOURCES += res.qrc
OTHER_FILES += settings.conf \
    friends.lst
