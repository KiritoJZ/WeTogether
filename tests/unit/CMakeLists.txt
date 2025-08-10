cmake_minimum_required(VERSION 3.21)
project(unit_tests)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Test)

add_executable(tst_core tst_core.cpp)
add_executable(tst_stores tst_stores.cpp)

target_include_directories(tst_core PRIVATE ../libs/core/include)
target_include_directories(tst_stores PRIVATE ../libs/stores/include)

target_link_libraries(tst_core PRIVATE Qt6::Core Qt6::Test core)
target_link_libraries(tst_stores PRIVATE Qt6::Core Qt6::Test stores)

add_test(NAME core_test COMMAND tst_core)
add_test(NAME stores_test COMMAND tst_stores)