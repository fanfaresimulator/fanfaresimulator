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
	include/instrument.hpp
	include/note.hpp
	include/partition.hpp
	include/noteglobale.hpp
	include/partitionglobale.hpp)

set(COMMON_SOURCE_FILES
	common/note.cpp
	common/partition.cpp
)

set(CLIENT_HEADER_FILES
	${COMMON_HEADER_FILES}
	include/client.hpp
	include/network_client.hpp
	include/network_utils.hpp
	include/keyboard.hpp
	include/ui.hpp
	include/InstrumentWindow.hpp
	gui/Utilisateur.hpp
)

set(CLIENT_SOURCE_FILES
	${COMMON_SOURCE_FILES}
	main.cpp
	network/network_client.cpp
	gui/keyboard.cpp
	gui/InstrumentWindow.cpp
	gui/Utilisateur.cpp
	engine/client.cpp)

set(SERVER_HEADER_FILES
	${COMMON_HEADER_FILES}
	include/server.hpp
	include/network_server.hpp
	include/network_utils.hpp
	include/serverconnection.hpp
	include/synthesizer.hpp
	include/ui.hpp
)

set(SERVER_SOURCE_FILES
	${COMMON_SOURCE_FILES}
	network/network_server.cpp
  network/serverconnection.cpp
	network/network_server.cpp
	synth/synthesizer.cpp
	synth/midi_handler.cpp
	server.cpp
	engine/server.cpp
)

add_executable(fanfaresimulator ${CLIENT_SOURCE_FILES} ${CLIENT_HEADER_FILES})
target_link_libraries(fanfaresimulator Qt5::Widgets Qt5::Network)

add_executable(fanfaresimulator-server ${SERVER_SOURCE_FILES} ${SERVER_HEADER_FILES})
target_include_directories(fanfaresimulator-server PRIVATE ${FLUIDSYNTH_INCLUDE_DIRS})
target_link_libraries(fanfaresimulator-server Qt5::Widgets Qt5::Network midifile ${FLUIDSYNTH_LIBRARIES})
