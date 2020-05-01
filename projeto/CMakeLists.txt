cmake_minimum_required(VERSION 3.15)
project(LIProject C)

set(CMAKE_C_STANDARD 99)

add_executable(LIProject main.c dados.h interface.c interface.h logica.c dados.c logica.h listas.c listas.h)