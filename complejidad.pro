#-------------------------------------------------
#
# Project created by QtCreator 2012-12-08T13:26:20
#
#-------------------------------------------------

QT       += core gui

TARGET = complejidad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp \
    board.cpp \
    city.cpp \
    constraintsmanager.cpp \
    solver.cpp

HEADERS  += mainwindow.h \
    canvas.h \
    board.h \
    city.h \
    constraintsmanager.h \
    solver.h

RESOURCES += \
    resources.qrc

LIBS += -L/usr/lib/lp_solve -llpsolve55
INCLUDEPATH = /usr/include/lpsolve
