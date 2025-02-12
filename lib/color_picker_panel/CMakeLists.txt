# Важно: включаем .ui файл в список исходников.
qt_add_library(colorpicker STATIC
    colorpicker.cpp
    colorpicker.hpp
    colorpicker.ui
)

target_link_libraries(colorpicker 
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
)

target_include_directories(colorpicker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

