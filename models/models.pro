TARGET = model
TEMPLATE = lib
CONFIG += shared c++14 x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers
DEPENDPATH  += ../helpers
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/blogobject.h
HEADERS += sqlobjects/userobject.h
HEADERS += user.h
SOURCES += user.cpp
HEADERS += sqlobjects/articleobject.h
HEADERS += article.h
SOURCES += article.cpp
HEADERS += sqlobjects/tagobject.h
HEADERS += tag.h
SOURCES += tag.cpp
