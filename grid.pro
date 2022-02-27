CONFIG += release precompile_header
QT += gui widgets
PRECOMPILED_HEADER = GridPch.h
SOURCES += main.cpp Cell.cpp Grid.cpp Row.cpp
HEADERS += GridPch.h Cell.h Grid.h Row.h
TARGET = grid

unix {
    QMAKE_CXXFLAGS_WARN_ON += -Wno-deprecated-copy
}
