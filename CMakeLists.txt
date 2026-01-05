cmake_minimum_required(VERSION 3.10)
project(IndustrialController)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Active AUTOMOC
set(CMAKE_AUTOMOC ON)

set(SOURCES
    src/main.cpp
    src/gui/MainWindow.cpp
    src/core/Sensor.cpp
    src/core/Controller.cpp
    src/core/Logger.cpp
    src/core/AlarmManager.cpp
)

set(HEADERS
    src/gui/MainWindow.hpp
    src/core/Sensor.hpp
    src/core/Controller.hpp
    src/core/Logger.hpp
    src/core/AlarmManager.hpp
)

add_executable(industrial_controller ${SOURCES} ${HEADERS})
target_link_libraries(industrial_controller Qt5::Widgets)
target_include_directories(industrial_controller PRIVATE src)