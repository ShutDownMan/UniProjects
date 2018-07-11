cmake_minimum_required(VERSION 3.11)
project(CLion)

set(CMAKE_CXX_STANDARD 11)

add_executable(CLion main.cpp polygon.h polygon.cpp circle.h circle.cpp complexpolygon.h complexpolygon.cpp Triangle.cpp Triangle.h Rectangle.cpp Rectangle.h)