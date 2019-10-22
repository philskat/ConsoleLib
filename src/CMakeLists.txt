set(CMAKE_CXX_FLAGS "-Wall -g")

add_library(consoleLib STATIC console.cpp console.hpp color.hpp color.cpp)

if (WIN32)
    target_compile_definitions(consoleLib PRIVATE CMAKE_WINDOWS)
endif()

if (UNIX AND NOT APPLE)
    target_compile_definitions(consoleLib PRIVATE CMAKE_LINUX)
endif()


set(CONSOLELIB_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Include directory for ConsoleLib")