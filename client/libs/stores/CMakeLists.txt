cmake_minimum_required(VERSION 3.21)
project(stores)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(stores STATIC 
    src/login_store.cpp
    include/stores/login_store.h
    include/stores/friend_store.h
    src/friend_store.cpp)
target_include_directories(stores PUBLIC include)
target_link_libraries(stores
    PUBLIC  network
    PRIVATE Qt6::Core)
