cmake_minimum_required(VERSION 3.21)
project(integration_tests)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Test)

add_executable(tst_login_flow tst_login_flow.cpp)

target_include_directories(tst_login_flow PRIVATE ../libs/core/include)

target_link_libraries(tst_login_flow PRIVATE Qt6::Core Qt6::Test core network stores plugin-sdk ui)

add_test(NAME login_flow_test COMMAND tst_login_flow)