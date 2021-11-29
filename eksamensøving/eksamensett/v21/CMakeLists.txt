cmake_minimum_required(VERSION 3.20)
project(v21)

set(CMAKE_CXX_STANDARD 20 -pthread)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(v21 main.cpp Button.h ToggleButton.cpp ToggleButton.h LinkButton.cpp LinkButton.h Button.cpp Angle.cpp Angle.h)

add_compile_options(-Wall -Wextra)
target_link_libraries(v21 PRIVATE Threads::Threads)
