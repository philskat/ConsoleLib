cmake_minimum_required(VERSION 3.5)

option(CONSOLECOLOR_BUILD_EXAMPLES "Build the examples" OFF)
option(CONSOLECOLOR_BUILD_TESTS "Build library tests" OFF)

project(consolecolor)

add_library(consolecolor STATIC)
target_include_directories(consolecolor PUBLIC include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(include)
add_subdirectory(src)

if(CONSOLECOLOR_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

if(CONSOLECOLOR_BUILD_TESTS)
  add_subdirectory(tests)
endif()