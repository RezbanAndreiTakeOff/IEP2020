cmake_minimum_required(VERSION 3.12)
project(operations VERSION 1.0.0)

add_library(operations operations.h operations.cpp)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE operations)
