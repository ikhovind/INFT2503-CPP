cmake_minimum_required(VERSION 3.20)
project(o8)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

add_executable(opg1 opg1.cpp)
add_executable(opg2 opg2.cpp Pair.cpp)
