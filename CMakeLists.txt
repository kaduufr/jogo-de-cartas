cmake_minimum_required(VERSION 3.19)
project(jogo_cartas C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(jogo_cartas
        main.c)
