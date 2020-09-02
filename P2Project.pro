#-------------------------------------------------
#
# Project created by QtCreator 2020-07-31T18:02:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P2Project
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
		view/source/mainwindow.cpp \
		view/source/canvas.cpp \
		view/source/colorbutton.cpp \
		model/source/entity.cpp \
		model/source/line.cpp \
		model/source/scene.cpp \
		model/source/singleton.cpp \
		model/source/circle.cpp \
		controller/source/drawlinetool.cpp \
		controller/source/selectiontool.cpp \
		controller/source/tool.cpp \
		controller/source/envstyle.cpp \
		controller/source/deletetool.cpp \
		controller/source/saveimage.cpp \
		controller/source/drawcircletool.cpp

HEADERS += \
		view/header/mainwindow.h \
		view/header/canvas.h \
		view/header/colorbutton.h \
		model/header/trasformable.h \
		model/header/selectable.h \
		model/header/drawable.h \
		model/header/entity.h \
		model/header/line.h \
		model/header/circle.h \
		model/header/scene.h \
		model/header/singleton.h \
		controller/header/tool.h \
		controller/header/drawlinetool.h \
		controller/header/selectiontool.h \
		controller/header/envstyle.h \
		controller/header/deletetool.h \
		controller/header/saveimage.h \
		controller/header/drawcircletool.h

RESOURCES += \
    resources.qrc
