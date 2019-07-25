cmake_minimum_required(VERSION 3.13)

find_package(Qt5 REQUIRED COMPONENTS Gui Qml Core)

set(CMAKE_AUTOMOC ON)

add_subdirectory(src)
