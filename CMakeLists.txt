cmake_minimum_required(VERSION 3.20)
project(simple_shell C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(simple_shell
        env_functions.c
        main.c
        main.h
        parse_data.c
        str-functions.c)
