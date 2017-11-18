# This is the version I am currently using
# TODO check if older versions will work when this is completed
cmake_minimum_required(VERSION 3.7.2)
project(Ryd3ngine)

# Create a list of all the files to use
set(SOURCE_FILES	src/ryd3_core.cpp
					src/ryd3_ResourceManager.cpp)

# Place the output in lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Create the library
add_library(Ryd3ngine STATIC ${SOURCE_FILES})
