cmake_minimum_required(VERSION 3.20)
project("triespline")

# Declare library & directories to include. See
# http://mariobadr.com/creating-a-header-only-library-with-cmake.html for more
# info/install instructions
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

# Make IDE friendly
target_sources(${PROJECT_NAME} INTERFACE triespline.hpp)
