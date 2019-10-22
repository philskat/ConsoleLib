add_executable(errorDisplay main.cpp error.cpp error.hpp)
target_include_directories(errorDisplay PRIVATE ${CONSOLELIB_INCLUDE_DIR})
target_link_libraries(errorDisplay consoleLib)