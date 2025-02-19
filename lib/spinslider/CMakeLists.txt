qt_add_library(spinslider STATIC
    spinslider.cpp
    spinslider.hpp
    spinslider.ui
)

target_link_libraries(spinslider
PUBLIC
    Qt6::Core
    Qt6::Widgets
)

target_include_directories(spinslider PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

