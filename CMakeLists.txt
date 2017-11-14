# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.2)

# Boost: asio library
find_package(Boost 1.40.0 REQUIRED)

# Project's name
project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp network/server.cpp)
add_executable(fanfaresimulator ${SOURCE_FILES})
