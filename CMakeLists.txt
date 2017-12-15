cmake_minimum_required(VERSION 3.2)

project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# Gimme warnings plz
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

list(INSERT CMAKE_MODULE_PATH 0
	${CMAKE_CURRENT_SOURCE_DIR}/CMake
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Fluidsynth REQUIRED)

include_directories(include)

add_subdirectory(midifile)

set(COMMON_HEADER_FILES
	include/synth/pupitre.hpp
	include/synth/instrument.hpp
	include/synth/note.hpp
	include/synth/partition.hpp
	include/synth/midi_handler.hpp
	include/synth/noteglobale.hpp
	include/synth/partitionglobale.hpp
	include/network/network.hpp
)

set(COMMON_SOURCE_FILES
	synth/note.cpp
	synth/noteglobale.cpp
	synth/partition.cpp
	synth/partitionglobale.cpp
	synth/pupitre.cpp
	synth/instrument.cpp
	synth/midi_handler.cpp
	network/network.cpp
)

set(CLIENT_HEADER_FILES
	${COMMON_HEADER_FILES}
	include/engine/client.hpp
	include/engine/state.hpp
	include/network/client.hpp
	include/network/discoverer.hpp
	include/gui/PupitreWindow.hpp
	include/gui/UsernameWindow.hpp
	include/gui/game_window.hpp
	include/gui/gui_note.hpp
	include/gui/music_line.hpp
)

set(CLIENT_SOURCE_FILES
	${COMMON_SOURCE_FILES}
	client.cpp
	network/client.cpp
	network/discoverer.cpp
	gui/PupitreWindow.cpp
	gui/UsernameWindow.cpp
	engine/client.cpp
	engine/state.cpp
	gui/game_window.cpp
	gui/music_line.cpp
	gui/gui_note.cpp
)

set(SERVER_HEADER_FILES
	${COMMON_HEADER_FILES}
	include/synth/sound_player.hpp
	include/synth/PartitionPlayer.hpp
	include/engine/server.hpp
	include/network/server.hpp
	include/network/serverconnection.hpp
	include/network/advertizer.hpp
	include/network/DelayEstimator.hpp
	include/network/SendAfter.hpp
)

set(SERVER_SOURCE_FILES
	${COMMON_SOURCE_FILES}
	server.cpp
	engine/server.cpp
	network/server.cpp
	network/advertizer.cpp
	network/serverconnection.cpp
	network/DelayEstimator.cpp
	network/SendAfter.cpp
	synth/sound_player.cpp
	synth/PartitionPlayer.cpp
)

add_executable(fanfaresimulator-client ${CLIENT_SOURCE_FILES} ${CLIENT_HEADER_FILES})
target_link_libraries(fanfaresimulator-client Qt5::Widgets Qt5::Network midifile)

add_executable(fanfaresimulator-server ${SERVER_SOURCE_FILES} ${SERVER_HEADER_FILES})
target_include_directories(fanfaresimulator-server PRIVATE ${FLUIDSYNTH_INCLUDE_DIRS})
target_link_libraries(fanfaresimulator-server Qt5::Widgets Qt5::Network midifile ${FLUIDSYNTH_LIBRARIES})
