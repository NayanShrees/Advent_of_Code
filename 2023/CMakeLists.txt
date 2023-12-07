cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(PROJECT AoC)

project(${PROJECT} VERSION 1.0)

set(SOURCE
    ${CMAKE_SOURCE_DIR}/src/days/day_1.cpp
    ${CMAKE_SOURCE_DIR}/src/util.cpp
)

set(PROJECT_LIB AdventOfCodeLib)
add_library(${PROJECT_LIB} ${SOURCE})
target_include_directories(${PROJECT_LIB} PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT} ${PROJECT_LIB})