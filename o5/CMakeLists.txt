cmake_minimum_required(VERSION 3.20)
project(o5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter")

add_executable(o5 main.cpp)
