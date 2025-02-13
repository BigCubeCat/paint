qt_add_library(stampconfig STATIC
    stampconfig.cpp
    stampconfig.hpp
    stampconfig.ui
)

target_link_libraries(stampconfig 
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
)

target_include_directories(stampconfig PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

