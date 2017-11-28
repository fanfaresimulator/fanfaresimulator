cmake_minimum_required(VERSION 3.2)

project(fanfaresimulator)

set(CMAKE_CXX_STANDARD 11)

list(INSERT CMAKE_MODULE_PATH 0
	${CMAKE_CURRENT_SOURCE_DIR}/CMake
)

find_package(Qt5Widgets REQUIRED)

set(CLIENT_HEADER_FILES
	include/client.hpp
	include/keyboard.hpp
	include/note.hpp
	include/partition.hpp
	include/synthesizer.hpp
	include/InstrumentWindow.hpp
	include/ui.hpp
	gui/testwindow.hpp
	gui/utilisateur.hpp)

set(CLIENT_SOURCE_FILES
	main.cpp
	gui/testwindow.cpp
	gui/InstrumentWindow.cpp
	gui/utilisateur.cpp)

set(SERVER_HEADER_FILES
	include/keyboard.hpp
	include/note.hpp
	include/partition.hpp
	include/server.hpp
	include/synthesizer.hpp
	include/ui.hpp)

set(SERVER_SOURCE_FILES
	server.cpp
	network/server.cpp)

add_executable(fanfaresimulator ${CLIENT_SOURCE_FILES} ${CLIENT_HEADER_FILES})
target_link_libraries(fanfaresimulator Qt5::Widgets)

add_executable(fanfaresimulator-server ${SERVER_SOURCE_FILES} ${SERVER_HEADER_FILES})
target_link_libraries(fanfaresimulator-server Qt5::Widgets)
