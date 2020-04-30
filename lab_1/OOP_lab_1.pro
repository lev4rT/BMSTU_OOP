QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    file.cpp \
    link.cpp \
    links_read.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    model_cdio.cpp \
    model_draw.cpp \
    model_load.cpp \
    model_operations.cpp \
    model_read.cpp \
    point_cdio.cpp \
    point_operations.cpp \
    screen.cpp \
    task_manager.cpp \
    wrap_functions.cpp

HEADERS += \
    file.h \
    link.h \
    links_read.h \
    mainwindow.h \
    meta.h \
    model.h \
    model_cdio.h \
    model_draw.h \
    model_load.h \
    model_operations.h \
    model_read.h \
    point_cdio.h \
    point_operations.h \
    scene.h \
    screen.h \
    task_manager.h \
    wrap_functions.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
