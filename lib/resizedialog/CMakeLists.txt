qt_add_library(resizedialog STATIC
    resizedialog.cpp
    resizedialog.hpp
    resizedialog.ui
)

target_link_libraries(resizedialog
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
)

target_include_directories(resizedialog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

