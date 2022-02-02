cmake_minimum_required(VERSION 3.20)
project(racional C)

set(CMAKE_C_STANDARD 99)

add_executable(racional main.c racional.c racional.h utilitarios.c utilitarios.h)
