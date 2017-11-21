cmake_minimum_required(VERSION 3.2)

project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)

list(INSERT CMAKE_MODULE_PATH 0
	${CMAKE_CURRENT_SOURCE_DIR}/CMake
)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

set(CLIENT_HEADER_FILES
	include/client.hpp
	include/network_client.hpp
	include/instrument.hpp
	include/keyboard.hpp
	include/note.hpp
	include/partition.hpp
	include/synthesizer.hpp
	include/ui.hpp)

set(CLIENT_SOURCE_FILES
	main.cpp
	network/network_client.cpp
	gui/testwindow.cpp)

set(SERVER_HEADER_FILES
	include/instrument.hpp
	include/keyboard.hpp
	include/note.hpp
	include/partition.hpp
	include/server.hpp
	include/network_server.hpp
	include/synthesizer.hpp
	include/ui.hpp)

set(SERVER_SOURCE_FILES
	server.cpp
	network/network_server.cpp
	gui/testwindow.cpp)

add_executable(fanfaresimulator ${CLIENT_SOURCE_FILES} ${CLIENT_HEADER_FILES})
target_link_libraries(fanfaresimulator Qt5::Widgets Qt5::Network)

add_executable(fanfaresimulator-server ${SERVER_SOURCE_FILES} ${SERVER_HEADER_FILES})
target_link_libraries(fanfaresimulator-server Qt5::Widgets Qt5::Network)
