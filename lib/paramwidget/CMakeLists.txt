qt_add_library(paramwidget STATIC
    paramwidget.cpp
    paramwidget.hpp
    paramwidget.ui
)

target_link_libraries(paramwidget
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
    lineconfig
)

target_include_directories(paramwidget PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

