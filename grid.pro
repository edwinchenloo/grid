#CONFIG += debug
QT += gui widgets
SOURCES += main.cpp Cell.cpp Grid.cpp Row.cpp
HEADERS += Cell.h Grid.h Row.h
TARGET = grid

QMAKE_CXXFLAGS_WARN_ON += -Wno-deprecated-copy
