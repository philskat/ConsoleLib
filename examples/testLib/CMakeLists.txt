add_executable(testLib main.cpp)
target_include_directories(testLib PRIVATE ${CONSOLELIB_INCLUDE_DIR})
target_link_libraries(testLib consoleLib)