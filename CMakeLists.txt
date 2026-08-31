cmake_minimum_required(VERSION 3.10)

project(Brodilka C)

add_executable(Brodilka
    src/main.c
    src/print.c
    src/rendering.c
)

target_compile_options(Brodilka PUBLIC -mwindows)