#include <QApplication>
#include "include/network/server.hpp"
#include "include/network/advertizer.hpp"
#include "include/server.hpp"
#include "include/sound_player.hpp"
#include "include/midi_handler.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	const char *filepath = "../resources/Movie_Themes_-_Willie_Wonka.mid";
	if (argc > 1) {
		filepath = argv[1];
	}

	Advertizer advertizer;
	NetworkServer networkServer;

	Partition mainPartition(filepath);
	//mainPartition.print();

	Sound_player sound_player;
	sound_player.testPartition(filepath);

	Server serverEngine(networkServer, mainPartition, sound_player);

	// Connect network server & server engine
	QObject::connect(&networkServer, &NetworkServer::helloRecv, &serverEngine,&Server::addClient);
	QObject::connect(&networkServer, &NetworkServer::pupitreChoiceRecv, &serverEngine, &Server::addPupitre);
	QObject::connect(&networkServer, &NetworkServer::noteRecv, &serverEngine, &Server::playNote);
	QObject::connect(&networkServer, &NetworkServer::readyRecv, &serverEngine, &Server::clientReady);

	return app.exec();
}
