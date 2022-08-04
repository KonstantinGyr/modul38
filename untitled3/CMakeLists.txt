cmake_minimum_required(VERSION 3.23)
project(untitled3)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

        find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        WebEngineWidgets
        REQUIRED
        )

target_link_libraries(untitled3
        Qt5::core
        Qt5::Gui
        Qt5::Widgets
        Qt5::WebEngineWidgets
        Qt5::WebEngineCore
        )

add_executable(untitled3 main.cpp)
