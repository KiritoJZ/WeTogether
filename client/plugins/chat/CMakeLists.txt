cmake_minimum_required(VERSION 3.21)
project(chat_plugin)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_add_plugin(chat SHARED
    src/chat_plugin.cpp
)
target_include_directories(chat PUBLIC include)
target_link_libraries(chat PRIVATE Qt6::Core Qt6::Widgets)