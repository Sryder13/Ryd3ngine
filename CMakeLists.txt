# This is the version I am currently using
# TODO check if older versions will work when this is completed
cmake_minimum_required(VERSION 3.7.2)
project(Ryd3ngine)

# Requires SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Create a list of all the files to use
set(SOURCE_FILES src/ryd3_core.cpp)

# Place the output in lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Create the library
add_library(Ryd3ngine STATIC ${SOURCE_FILES})
target_link_libraries(Ryd3ngine ${SDL2_LIBRARY})