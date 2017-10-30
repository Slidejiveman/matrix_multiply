cmake_minimum_required(VERSION 3.8)
project(matrix_multiply)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(matrix_multiply ${SOURCE_FILES})