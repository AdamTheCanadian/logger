cmake_minimum_required(VERSION 3.00)
project(logger VERSION 0.0.1)

# Set all the compiler and build flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_FLAGS -Wall)

# This macro is used in the logging application to remove the full path of the 
# filename (instead of /home/user/.../.cpp), just keep the .cpp part
string(LENGTH "${CMAKE_SOURCE_DIR}/" SOURCE_PATH_SIZE)
add_definitions("-DSOURCE_PATH_SIZE=${SOURCE_PATH_SIZE}")

add_executable(
  log_example
  main.cpp
  include/logger/logger.h)

add_executable(
  log_threading_example
  log_threading_example.cpp
  include/logger/logger.h)

target_link_libraries(log_threading_example pthread)