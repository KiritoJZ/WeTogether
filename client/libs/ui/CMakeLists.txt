cmake_minimum_required(VERSION 3.21)
project(ui)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_library(ui STATIC
    src/login_widget.cpp
    include/ui/login_widget.h
    include/ui/main_window.h
    src/main_window.cpp)
target_include_directories(ui PUBLIC include)
target_link_libraries(ui
    PUBLIC  stores
    PRIVATE Qt6::Core Qt6::Widgets)
