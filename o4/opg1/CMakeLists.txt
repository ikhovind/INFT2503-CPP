cmake_minimum_required(VERSION 3.20)
project(o4)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -pedantic -Werror)
add_executable(o4 opg1.cpp)
