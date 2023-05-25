cmake_minimum_required(VERSION 3.26.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(blocks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(src/)
add_subdirectory(tst/)
add_subdirectory(app/)
