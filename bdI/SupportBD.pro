QT       += core gui
QT       += sql
INCLUDEPATH += C:\Qt\Docs\Qt-6.6.1\qtsql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bdeshka.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    registration.cpp

HEADERS += \
    bdeshka.h \
    login.h \
    mainwindow.h \
    registration.h

FORMS += \
    bdeshka.ui \
    login.ui \
    mainwindow.ui \
    registration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
