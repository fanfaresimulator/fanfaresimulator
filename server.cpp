#include <QApplication>
#include "include/network/server.hpp"
#include "include/network/advertizer.hpp"
#include "include/server.hpp"
#include "include/sound_player.hpp"
#include "include/midi_handler.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	Advertizer advertizer;
	NetworkServer networkServer;

	Partition mainPartition("../resources/Movie_Themes_-_Willie_Wonka.mid");
	//mainPartition.print();

	Sound_player sound_player;
	//sound_player.testPlayer();

	Server serverEngine(networkServer, mainPartition, sound_player);

	// Connect network server & server engine
	QObject::connect(&networkServer, &NetworkServer::helloRecv, &serverEngine,&Server::addClient);
	QObject::connect(&networkServer, &NetworkServer::pupitreChoiceRecv, &serverEngine, &Server::addPupitre);
	QObject::connect(&networkServer, &NetworkServer::noteRecv, &serverEngine, &Server::playNote);
	QObject::connect(&networkServer, &NetworkServer::readyRecv, &serverEngine, &Server::clientReady);

	return app.exec();
}
