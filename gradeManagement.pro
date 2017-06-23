#-------------------------------------------------
#
# Project created by QtCreator 2017-05-29T10:00:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gradeManagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
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
        db.cpp \
        student.cpp \
    insertgrade.cpp \
    insertstudent.cpp \
    selectgrade.cpp \
    selectstudent.cpp \
    course.cpp \
    insertcourse.cpp \
    selectcourse.cpp \
    grade.cpp
        dialog.cpp

HEADERS += \
        mainwindow.h \
        db.h \
        student.h \
    insertgrade.h \
    insertstudent.h \
    selectgrade.h \
    selectstudent.h \
    course.h \
    insertcourse.h \
    selectcourse.h \
    grade.h

FORMS += \
        mainwindow.ui \
    insertstudent.ui \
    selectgrade.ui \
    selectstudent.ui \
    insertcourse.ui \
    selectcourse.ui \
    insertgrade.ui
    selectstudent.ui

RESOURCES += \
    welcome.qrc

DISTFILES +=
