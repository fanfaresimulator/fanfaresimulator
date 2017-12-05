cmake_minimum_required(VERSION 3.2)

project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)

list(INSERT CMAKE_MODULE_PATH 0
	${CMAKE_CURRENT_SOURCE_DIR}/CMake
)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Fluidsynth REQUIRED)

include_directories(include)

add_subdirectory(midifile)

set(COMMON_HEADER_FILES
	include/pupitre.hpp
	include/instrument.hpp
	include/note.hpp
	include/partition.hpp
	include/midi_handler.hpp
	include/noteglobale.hpp
	include/partitionglobale.hpp
	include/network/network.hpp
)

set(COMMON_SOURCE_FILES
	synth/note.cpp
	synth/noteglobale.cpp
	synth/partition.cpp
	synth/pupitre.cpp
	synth/instrument.cpp
	synth/midi_handler.cpp
	network/network.cpp
)

set(CLIENT_HEADER_FILES
	${COMMON_HEADER_FILES}
	include/client.hpp
	include/network/client.hpp
	include/network/discoverer.hpp
	include/keyboard.hpp
	include/ui.hpp
	include/PupitreWindow.hpp
	include/UsernameWindow.hpp
)

set(CLIENT_SOURCE_FILES
	${COMMON_SOURCE_FILES}
	main.cpp
	network/client.cpp
	network/discoverer.cpp
	gui/keyboard.cpp
	gui/PupitreWindow.cpp
	gui/UsernameWindow.cpp
	engine/client.cpp
	include/sound_player.h
)

set(SERVER_HEADER_FILES
	${COMMON_HEADER_FILES}
	include/sound_player.hpp
	include/server.hpp
	include/network/server.hpp
	include/network/serverconnection.hpp
	include/network/advertizer.hpp
	include/ui.hpp
)

set(SERVER_SOURCE_FILES
	${COMMON_SOURCE_FILES}
	server.cpp
	engine/server.cpp
	network/server.cpp
	network/advertizer.cpp
	network/serverconnection.cpp
	synth/sound_player.cpp
)

add_executable(fanfaresimulator ${CLIENT_SOURCE_FILES} ${CLIENT_HEADER_FILES})
target_link_libraries(fanfaresimulator midifile Qt5::Widgets Qt5::Network)

add_executable(fanfaresimulator-server ${SERVER_SOURCE_FILES} ${SERVER_HEADER_FILES})
target_include_directories(fanfaresimulator-server PRIVATE ${FLUIDSYNTH_INCLUDE_DIRS})
target_link_libraries(fanfaresimulator-server Qt5::Widgets Qt5::Network midifile ${FLUIDSYNTH_LIBRARIES})
