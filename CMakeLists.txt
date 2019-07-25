cmake_minimum_required(VERSION 3.13)

find_package(Qt5 REQUIRED COMPONENTS Gui Qml Core)

set(CMAKE_AUTOMOC ON)

configure_file(date_formats.txt date_formats.txt COPYONLY)

add_subdirectory(src)
