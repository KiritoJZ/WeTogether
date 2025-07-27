cmake_minimum_required(VERSION 3.21)
project(ui)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_library(ui STATIC
    src/login_widget.cpp)
target_include_directories(ui PUBLIC include)
target_link_libraries(ui PRIVATE Qt6::Core Qt6::Widgets)