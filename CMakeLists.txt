cmake_minimum_required(VERSION 3.21)
project(WeTogether-frontend VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

# 统一输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/stage/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/stage/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/stage/lib")

set(QT_QML_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/stage/qml")

add_subdirectory(libs)
#add_subdirectory(plugins)
add_subdirectory(apps)
#enable_testing()
#add_subdirectory(tests)

