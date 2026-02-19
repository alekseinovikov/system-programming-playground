cmake_minimum_required(VERSION 3.16)

project(system_programming_playground C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(lib)
add_subdirectory(hello)
add_subdirectory(io)
