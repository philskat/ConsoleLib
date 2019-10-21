set(CMAKE_CXX_FLAGS "-Wall -g")

add_library(console STATIC console.cpp console.hpp color.hpp color.cpp)

set(CONSOLELIB_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Include directory for ConsoleLib")