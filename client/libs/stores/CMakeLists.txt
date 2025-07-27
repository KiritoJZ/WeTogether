cmake_minimum_required(VERSION 3.21)
project(stores)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(stores STATIC 
    src/login_store.cpp)
target_include_directories(stores PUBLIC include)
target_link_libraries(stores PRIVATE Qt6::Core)