cmake_minimum_required(VERSION 3.00)
project(logger VERSION 0.0.1)

# Set all the compiler and build flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_FLAGS -Wall)

add_executable(
  log_example
  main.cpp
  include/logger/logger.h)