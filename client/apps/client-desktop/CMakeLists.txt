cmake_minimum_required(VERSION 3.21)
project(client-desktop)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(client-desktop src/main.cpp)
target_link_libraries(client-desktop PRIVATE Qt6::Core Qt6::Widgets)