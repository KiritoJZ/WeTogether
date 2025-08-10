cmake_minimum_required(VERSION 3.16)
project(ui_publicComponet LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Quick QuickControls2)
qt_standard_project_setup()
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

# --------- QML plugin ----------
qt6_add_qml_module(ui_publicComponet
  URI "PublicComponet"
  VERSION 1.0
  SHARED
  SOURCES

  QML_FILES
    qml/WindowBehavior.qml
  RESOURCES

)

# --------- headers -------------
target_include_directories(ui_login
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# --------- linking -------------
target_link_libraries(ui_publicComponet
  PUBLIC
    Qt6::Core
    Qt6::Quick
    Qt6::QuickControls2
)
