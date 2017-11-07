# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.6)

# Project's name
project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(code ${SOURCE_FILES})