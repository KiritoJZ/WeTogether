cmake_minimum_required(VERSION 3.21)
project(network)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_library(network STATIC src/api_client.cpp
    include/network/api_client.h)
target_include_directories(network PUBLIC include)
target_link_libraries(network PRIVATE Qt6::Core Qt6::Network)
