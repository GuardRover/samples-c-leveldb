TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/Qt/Tools/leveldb/include"
LIBS += "-LC:/Qt/Tools/leveldb/lib" -lleveldb

SOURCES += \
        src/ldb.cpp
