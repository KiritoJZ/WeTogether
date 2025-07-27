cmake_minimum_required(VERSION 3.21)
project(WeTogether VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(libs)
add_subdirectory(plugins)
add_subdirectory(apps)
enable_testing()
add_subdirectory(tests)