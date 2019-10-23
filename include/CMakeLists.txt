set(CONSOLELIB_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Include directory for ConsoleLib")

target_sources(consoleLib PRIVATE
                                ${CMAKE_CURRENT_LIST_DIR}/color.hpp
                                ${CMAKE_CURRENT_LIST_DIR}/console.hpp
)