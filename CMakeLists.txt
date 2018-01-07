# This is the version I am currently using
# TODO check if older versions will work when this is completed
cmake_minimum_required(VERSION 3.7.2)
project(Ryd3ngine)

# include libs
include_directories(${CMAKE_SOURCE_DIR}/libs)

# Requires OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# Requires GLEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIR})

# Requires SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Requires SDL2 Image
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

# Requires SDL2 Mixer
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2MIXER_INCLUDE_DIR})

# Requires Assimp
find_package(assimp REQUIRED)
include_directories(${assimp_INCLUDE_DIRS})

# Create a list of all the files to use
set(SOURCE_FILES	src/ryd3_core.cpp
			src/ryd3_ResourceManager.cpp
			src/ryd3_texture.cpp
			src/ryd3_model.cpp
			src/ryd3_camera.cpp
			src/ryd3_entity.cpp
			src/ryd3_entitymanager.cpp
			src/ryd3_sound.cpp
			src/ryd3_music.cpp
			src/ryd3_shader.cpp)

# Place the output in lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Create the library
add_library(Ryd3ngine STATIC ${SOURCE_FILES})
