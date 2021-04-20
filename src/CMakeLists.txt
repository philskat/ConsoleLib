set(CMAKE_CXX_FLAGS "-Wall -g")

target_sources(consolecolor PRIVATE
                                ${CMAKE_CURRENT_LIST_DIR}/console.cpp
                                ${CMAKE_CURRENT_LIST_DIR}/color.cpp
)

if (WIN32)
    target_compile_definitions(consolecolor PRIVATE CMAKE_WINDOWS)
endif()

if (UNIX AND NOT APPLE)
    target_compile_definitions(consolecolor PRIVATE CMAKE_LINUX)
endif()