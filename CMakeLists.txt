cmake_minimum_required(VERSION 3.19)
project(icg_paint LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt6_add_resources(RESOURCES resources.qrc)

qt_standard_project_setup()

# Добавляем исполняемый файл без файлов mainwindow
qt_add_executable(icg_paint
    WIN32 MACOSX_BUNDLE
    main.cpp
    # Убираем файлы mainwindow/*.*
    ${RESOURCES}
)


# Линкуем с библиотеками, включая библиотеку mainwindow
target_link_libraries(icg_paint
    PRIVATE
        Qt::Core
        Qt::Widgets
        mainwindow
        canvas
        colorpicker
        lineconfig
        paramwidget
        stampconfig
        resizedialog
    PUBLIC
        common_lib
        tools_lib
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
add_subdirectory(lib/tools)
add_subdirectory(lib/lineconfig)
add_subdirectory(lib/paramwidget)
add_subdirectory(lib/stampconfig)
add_subdirectory(lib/resizedialog)


