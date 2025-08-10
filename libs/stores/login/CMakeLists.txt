cmake_minimum_required(VERSION 3.16)
project(network LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Network)
qt_standard_project_setup()

add_library(StoresLib SHARED)

target_include_directories(StoresLib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/login>
)

target_sources(StoresLib PRIVATE
    src/LoginStore.cpp
    include/login/LoginStore.h
)

find_package(Qt6 REQUIRED COMPONENTS Core)
target_link_libraries(StoresLib
    PUBLIC
        Qt6::Core
        NetworkLib
)

target_compile_definitions(StoresLib PRIVATE STORESLIB_BUILD)
