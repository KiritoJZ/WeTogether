cmake_minimum_required(VERSION 3.21)
project(WeTogetherTests)

include_directories(${CMAKE_SOURCE_DIR}/libs/include)

find_package(Qt6 REQUIRED COMPONENTS Test)

add_subdirectory(unit)
add_subdirectory(integration)