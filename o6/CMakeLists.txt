cmake_minimum_required(VERSION 3.20)
project(o6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter -pthread")

add_executable(o6 opg1.cpp)
add_executable(o6_2 opg2.cpp)
