target_sources(consoleLib PRIVATE
                            ${CMAKE_CURRENT_LIST_DIR}/console.hpp
                            ${CMAKE_CURRENT_LIST_DIR}/color.hpp)
							
set(CONSOLELIB_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to consoleLib include files")