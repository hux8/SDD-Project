#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T11:09:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SDDD
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    verification.cpp \
    homepage.cpp \
    pitchui.cpp \
    projectui.cpp \
    confirmdialog.cpp \
    changecode.cpp \
    project.cpp \
    addpitch.cpp \
    addproject.cpp \
    pitch.cpp

HEADERS += \
        mainwindow.h \
    verification.h \
    homepage.h \
    pitchui.h \
    projectui.h \
    confirmdialog.h \
    changecode.h \
    addpitch.h \
    pitch.h \
    project.h \
    addproject.h

FORMS += \
        mainwindow.ui \
    verification.ui \
    homepage.ui \
    pitchui.ui \
    projectui.ui \
    confirmdialog.ui \
    changecode.ui \
    addpitch.ui \
    addproject.ui
