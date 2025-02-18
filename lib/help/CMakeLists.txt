qt_add_library(help_lib STATIC
    help.cpp
    help.hpp
    help.ui
)

target_link_libraries(help_lib
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
)

target_include_directories(help_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

