cmake_minimum_required(VERSION 3.20)
project(listadupenc C)

set(CMAKE_C_STANDARD 99)

add_executable(listadupenc main.c listadup.c listadup.h)
