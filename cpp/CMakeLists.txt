cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME algorithms)
set(PROJECT_DESCRIPTION "collection of algorithm implementations")

project(${PROJECT_NAME} VERSION 1.0
                        DESCRIPTION ${PROJECT_DESCRIPTION}
                        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PLATFORM_INDEPENDENT_CODE ON)

add_definitions(-std=c++17)

find_package(Catch2 3 REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)

include(CTest)
enable_testing()

include_directories(include)

add_subdirectory(tests)
add_subdirectory(src)
