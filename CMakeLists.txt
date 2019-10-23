cmake_minimum_required(VERSION 3.5)

option(CONSOLELIB_BUILD_EXAMPLES "Build the examples" ON)

project(ConsoleLib)

add_library(consoleLib STATIC)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(examples)