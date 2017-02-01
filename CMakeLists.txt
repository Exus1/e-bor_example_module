cmake_minimum_required(VERSION 3.2.2)

project(e-bot_example_module)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "RELEASE")
endif()

# GCC Flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

#CXX Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Release CXX Flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Debug CXX Flags
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

#Library output folder
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "Plugins")

# Build architecture
if(NOT DEFINED BUILD_x86)
	set(BUILD_ARCH "x86_64")
	set(BUILD_ARCH_OPTION "-m64")
else()
	set(BUILD_ARCH "x86")
	set(BUILD_ARCH_OPTION "-m32")
endif()

# Set build architecture
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${BUILD_ARCH_OPTION}")

# TeamSpeak3-C-Query-API headers
include_directories(
	TeamSpeak3-C-Query-API_headers
)

# e-bot include direcotry
include_directories(
	src/includes
)

# Library folder
link_directories(${CMAKE_SOURCE_DIR}/libs)

# Set of e-bot cpp files
set(SRCS
	src/main.cpp
)

add_library(your_module_name MODULE ${SRCS})

# Link TeamSpeak3-C-Query-API library
target_link_libraries(your_module_name teamspeak-api-${BUILD_ARCH})

