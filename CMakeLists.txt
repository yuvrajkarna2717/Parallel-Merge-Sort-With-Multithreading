cmake_minimum_required(VERSION 3.10)
project(parallel_merge_sort)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(main
    src/main.cpp
    src/serial_sort.cpp
    src/parallel_sort.cpp
)
