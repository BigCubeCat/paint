qt_add_library(lineconfig STATIC
    lineconfig.cpp
    lineconfig.hpp
    lineconfig.ui
)

target_link_libraries(lineconfig 
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
)

target_include_directories(lineconfig PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

