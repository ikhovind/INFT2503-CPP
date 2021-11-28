cmake_minimum_required(VERSION 3.20)
project(v21)

set(CMAKE_CXX_STANDARD 20)

add_executable(v21 main.cpp Button.h ToggleButton.cpp ToggleButton.h LinkButton.cpp LinkButton.h Button.cpp)
