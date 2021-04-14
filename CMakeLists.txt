cmake_minimum_required(VERSION 3.10)
project(Vetores C)

set(CMAKE_C_STANDARD 99)

add_executable(Vetores
        main.c
        vetor_double.h vetor_double.c)