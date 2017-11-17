# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.2)

# Project's name
project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp network/server.cpp gui/testwindow.cpp gui/testwindow.h include/server.hpp include/instrument.hpp)

find_package(Qt5Widgets)
add_executable(fanfaresimulator ${SOURCE_FILES})

target_link_libraries(fanfaresimulator Qt5::Widgets)
