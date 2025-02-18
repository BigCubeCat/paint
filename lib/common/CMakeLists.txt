cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME common_lib)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(${PROJECT_NAME} STATIC
  i_tool.hpp
  e_tool.hpp
  state.hpp
  state.cpp
  utils.hpp
  polygon_config.hpp
)

target_link_libraries(${PROJECT_NAME} 
PRIVATE
  Qt${QT_VERSION_MAJOR}::Widgets
PUBLIC
  tools_lib
)

target_compile_definitions(${PROJECT_NAME} PRIVATE CANVAS_LIBRARY)
