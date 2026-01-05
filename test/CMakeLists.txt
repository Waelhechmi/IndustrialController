cmake_minimum_required(VERSION 3.10)
project(IndustrialControllerTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ../src/core)

# Liste des sources réelles du projet à tester
set(PROJECT_SOURCES
    ../src/core/Sensor.cpp
    ../src/core/AlarmManager.cpp
    ../src/core/Controller.cpp  # si nécessaire
)

add_executable(runTests
    main.cpp
    test_sensor.cpp
    test_alarm.cpp
    ${PROJECT_SOURCES} 
)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_test(NAME AllTests COMMAND runTests)
