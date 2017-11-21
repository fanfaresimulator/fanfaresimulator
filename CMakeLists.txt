cmake_minimum_required(VERSION 3.6)
project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)

list(INSERT CMAKE_MODULE_PATH 0
	${CMAKE_CURRENT_SOURCE_DIR}/CMake
)

find_package(Qt5Widgets REQUIRED)
find_package(Fluidsynth REQUIRED)

include_directories(${FLUIDSYNTH_INCLUDE_DIRS})

set(HEADER_FILES
	# include/client.hpp
	# include/server.hpp
	# include/instrument.hpp
	# include/partition.hpp
	# include/ui.hpp
	)

set(SOURCE_FILES
	main.cpp
	# network/server.cpp
	# gui/testwindow.cpp
	synth/synthesizer.cpp
	synth/midi_handler.cpp
	)

add_executable(fanfaresimulator ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(fanfaresimulator Qt5::Widgets ${FLUIDSYNTH_LIBRARIES})

