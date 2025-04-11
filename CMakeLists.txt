cmake_minimum_required(VERSION 3.25)

# Select compiler for project
set(CMAKE_CXX_COMPILER "/opt/intel/oneapi/compiler/latest/bin/icpx")
project(ml4avx CXX)

message(STATUS "ENV{MKLROOT}: $ENV{MKLROOT}")

# Default build type is Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Compiler specific options
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -mavx")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find MLK Library
find_package(MKL CONFIG REQUIRED)
enable_testing()

# Fetch .cpp files
file(GLOB CXX_SRCS "src/*.cpp" "src/Ops/*.cpp")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(src src/Ops)

add_executable(${PROJECT_NAME} ${CXX_SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE MKL::MKL)

add_test(NAME mkl_version COMMAND mkl_version)
