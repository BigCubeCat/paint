cmake_minimum_required(VERSION 3.19)
project(icg_paint LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

# Добавляем исполняемый файл без файлов mainwindow
qt_add_executable(icg_paint
    WIN32 MACOSX_BUNDLE
    main.cpp
    # Убираем файлы mainwindow/*.*
)

# Линкуем с библиотеками, включая библиотеку mainwindow
target_link_libraries(icg_paint
    PRIVATE
        Qt::Core
        Qt::Widgets
        mainwindow
        canvas
        colorpicker
    PUBLIC
        common_lib
)

include(GNUInstallDirs)

install(TARGETS icg_paint
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET icg_paint
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

add_subdirectory(lib/canvas)
add_subdirectory(lib/common)
add_subdirectory(lib/color_picker_panel)
add_subdirectory(lib/mainwindow)


