cmake_minimum_required(VERSION 3.30)
project(untitled C)

set(CMAKE_C_STANDARD 17)

add_executable(untitled main.c
        functions.h
        functions.c
        lsd.c
        lsd.h
        tests.c
        tests.h)
