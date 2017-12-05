#include "include/network/server.hpp"
#include "include/network/advertizer.hpp"
#include "include/server.hpp"
#include "include/sound_player.hpp"
#include "include/midi_handler.hpp"

#include <QApplication>

#ifdef __unix__
#include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	Advertizer advertizer;
	NetworkServer networkServer;
	// create main partition here !
	Partition mainPartition = Partition();
	Sound_player* S = new Sound_player();

//  S->testPlayer();

	Server serverEngine(networkServer, mainPartition, *S);

    /* CONNECTS network server & server engine */

	QObject::connect(&networkServer, &NetworkServer::helloRecv,
					 &serverEngine, &Server::addClient);

	QObject::connect(&networkServer, &NetworkServer::partitionChoiceRecv,
					 &serverEngine, &Server::addPupitre);

	QObject::connect(&networkServer, &NetworkServer::noteRecv,
					 &serverEngine, &Server::playNote);

	QObject::connect(&networkServer, &NetworkServer::readyReceived,
					 &serverEngine, &Server::clientReady);

//    delete(S);
	return app.exec();
}
