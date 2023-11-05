cmake_minimum_required(VERSION 3.16)
project(snoopingCar LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
)

qt_add_executable(snoopingCar ${PROJECT_SOURCES})

target_link_libraries(snoopingCar
    PUBLIC
        Qt::Core
)
