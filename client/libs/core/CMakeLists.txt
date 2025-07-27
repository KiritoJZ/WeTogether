cmake_minimum_required(VERSION 3.21)
project(core)

add_library(core STATIC
    src/utils.cpp)

target_include_directories(core PUBLIC include)