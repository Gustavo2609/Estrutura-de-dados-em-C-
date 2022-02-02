cmake_minimum_required(VERSION 3.20)
project(pilha_est C)

set(CMAKE_C_STANDARD 99)

add_executable(pilha_est main.c pilha.c pilha.h)
