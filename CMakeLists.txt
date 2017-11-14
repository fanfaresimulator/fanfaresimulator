# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.2)

# Project's name
project(fanfaresimulator)

# Boost: asio library
find_package(Boost 1.54.0 REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp network/server.cpp)
add_executable(fanfaresimulator ${SOURCE_FILES})
