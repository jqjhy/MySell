cmake_minimum_required(VERSION 3.22.1)
project(shell)
include_directories(src/)
set(CMAKE_CXX_STANDARD 17)
add_executable( shell
        src/Main.cc
        src/myhead.h
)