#-------------------------------------------------
#
# Project created by QtCreator 2019-06-25T21:31:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PractikaLeto2019
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
        enums.cpp \
        floormap.cpp \
        group.cpp \
        human.cpp \
        main.cpp \
        mytime.cpp \
        painthelper2.cpp \
        simulation.cpp \
        student.cpp \
        teacher.cpp \
        timesheet.cpp

HEADERS += \
        enums.h \
        floormap.h \
        group.h \
        human.h \
        mytime.h \
        painthelper2.h \
        simulation.h \
        student.h \
        teacher.h \
        timesheet.h

FORMS += \
        simulation.ui
