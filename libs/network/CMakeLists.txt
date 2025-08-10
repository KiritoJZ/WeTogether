cmake_minimum_required(VERSION 3.16)
project(network LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Network)
qt_standard_project_setup()

add_library(NetworkLib SHARED)

target_include_directories(NetworkLib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(NetworkLib PRIVATE
    src/HttpClient.cpp
    src/GatewayConfig.cpp
    include/GatewayConfig.h
    include/HttpClient.h
)

find_package(Qt6 REQUIRED COMPONENTS Network)
target_link_libraries(NetworkLib
    PUBLIC
        Qt6::Core
        Qt6::Network
)

target_compile_definitions(NetworkLib PRIVATE NETWORKLIB_BUILD)
