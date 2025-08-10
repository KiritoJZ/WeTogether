cmake_minimum_required(VERSION 3.16)
project(ui_login LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Quick QuickControls2)
qt_standard_project_setup()
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

# --------- QML plugin ----------
qt6_add_qml_module(ui_login
  URI "Login"
  VERSION 1.0
  SHARED
  SOURCES
    src/controllers/LoginController.cpp
    src/models/UserModel.cpp
    include/controllers/LoginController.h
    include/models/UserModel.h
  QML_FILES
    qml/views/LoginView.qml
    qml/components/LoginInput.qml
    qml/components/LoginButton.qml
    qml/components/RoundedImage.qml
    qml/components/LoginTitleBar.qml
  RESOURCES
    resources/avatar.png
)

# --------- headers -------------
target_include_directories(ui_login
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/controllers>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/models>
    $<INSTALL_INTERFACE:include>
)

# --------- linking -------------
target_link_libraries(ui_login
  PUBLIC
    Qt6::Core
    Qt6::Quick
    Qt6::QuickControls2
    StoresLib
    ui_publicComponet
)

target_compile_definitions(ui_login PRIVATE UI_LOGIN_BUILD)
