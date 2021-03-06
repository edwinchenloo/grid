cmake_minimum_required(VERSION 3.1.0)

project(qscene VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(QT${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(grid
    main.cpp

    Cell.cpp
    Grid.cpp
    Row.cpp

    Cell.h
    Grid.h
    Row.h
)

target_precompile_headers(grid PUBLIC GridPch.h)
target_link_libraries(grid Qt${QT_VERSION_MAJOR}::Widgets)
