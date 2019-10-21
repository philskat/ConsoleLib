set(CMAKE_CXX_FLAG "-Wall -g")

add_executable(sandbox main.cpp)
target_include_directories(sandbox PRIVATE ${CONSOLELIB_INCLUDE_DIR})
target_link_libraries(sandbox console)