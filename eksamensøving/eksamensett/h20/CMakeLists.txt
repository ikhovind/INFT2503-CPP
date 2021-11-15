cmake_minimum_required(VERSION 3.20)
project(h20)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(h20 main.cpp ThreadSafeGrowingList.cpp RGB.cpp Map.cpp Filter.cpp)
target_link_libraries(h20 Threads::Threads)