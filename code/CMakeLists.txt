cmake_minimum_required(VERSION 3.23)
project(chess C)

set(CMAKE_C_STANDARD 99)

add_executable(chess main.c five_game.c five_game.h)
