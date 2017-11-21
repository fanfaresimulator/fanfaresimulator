cmake_minimum_required(VERSION 3.2)

project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)

list(INSERT CMAKE_MODULE_PATH 0
	${CMAKE_CURRENT_SOURCE_DIR}/CMake
)

find_package(Qt5Widgets REQUIRED)
find_package(Portaudio 19 REQUIRED)

include_directories(${PORTAUDIO_INCLUDE_DIRS})

set(SOURCE_FILES
	main.cpp
	network/server.cpp
	gui/testwindow.cpp
	include/client.hpp)

add_executable(fanfaresimulator ${SOURCE_FILES})
target_link_libraries(fanfaresimulator Qt5::Widgets)

add_executable(synth_test synth/synth.cpp)
target_link_libraries(synth_test ${PORTAUDIO_LIBRARIES})
