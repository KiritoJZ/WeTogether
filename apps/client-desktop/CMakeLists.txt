cmake_minimum_required(VERSION 3.24)
project(client-desktop LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Qml)
qt_standard_project_setup()

qt6_add_executable(client-desktop
  src/main.cpp
)

qt6_add_qml_module(client-desktop
    URI  App
    VERSION 1.0
    IMPORTS
        Login 1.0
)


target_link_libraries(client-desktop
  PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Qml
    ui_main
)

