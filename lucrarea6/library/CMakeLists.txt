add_library(operations
            operations/operations.h
            operations/operations.cpp)


target_include_directories(operations PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
