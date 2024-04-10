cmake_minimum_required(VERSION 3.27)
project(op15 C)

set(CMAKE_C_STANDARD 11)

add_executable(op15 main.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h)
