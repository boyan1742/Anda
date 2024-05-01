cmake_minimum_required(VERSION 3.28)
project(Anda C)

set(CMAKE_C_STANDARD 11)

add_executable(Anda main.c
        include/Generator.h
        include/Array.h)
