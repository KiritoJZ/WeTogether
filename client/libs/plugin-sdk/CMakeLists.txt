cmake_minimum_required(VERSION 3.21)
project(plugin-sdk)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(plugin-sdk SHARED src/plugin_manager.cpp)
target_include_directories(plugin-sdk PUBLIC include)
target_link_libraries(plugin-sdk PRIVATE Qt6::Core)