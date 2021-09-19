cmake_minimum_required(VERSION 3.1)

project(o3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(opg2 opg2.cpp)
add_executable(opg3 opg3.cpp commodity.cpp)
add_executable(opg4 opg4.cpp)
