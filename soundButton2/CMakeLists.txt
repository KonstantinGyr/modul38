cmake_minimum_required(VERSION 3.21)
project(soundButton2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

add_executable(soundButton2 main.cpp)
target_link_libraries(soundButton2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        )
