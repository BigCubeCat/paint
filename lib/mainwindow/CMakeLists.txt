# Важно: включаем .ui файл в список исходников.
qt_add_library(mainwindow STATIC
    mainwindow.cpp
    mainwindow.hpp
    mainwindow.ui
)

target_link_libraries(mainwindow PUBLIC
    Qt6::Core
    Qt6::Widgets
    PRIVATE
    colorpicker
)

target_include_directories(mainwindow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

