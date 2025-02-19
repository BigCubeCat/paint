qt_add_library(polygondialog STATIC
    polygondialog.cpp
    polygondialog.hpp
    polygondialog.ui
)

target_link_libraries(polygondialog
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
    lineconfig
    spinslider
)

target_include_directories(polygondialog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

