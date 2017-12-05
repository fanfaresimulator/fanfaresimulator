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

	//midi_handler();
	//testSynth();

	Advertizer advertizer;

	NetworkServer networkServer;

  Sound_player* S = new Sound_player();

  S->testPlayer();


//	Synthesizer synthesizer;
	Server serverEngine(networkServer);

    /* CONNECTS network server & server engine */

//	QObject::connect(&networkServer, &NetworkServer::helloRecv,
//					 &serverEngine, &Server::addClient);
//
//	QObject::connect(&networkServer, &NetworkServer::instrumentChoiceRecv,
//					 &serverEngine, &Server::addInstrument);
//
//	QObject::connect(&networkServer, &NetworkServer::noteRecv,
//					 &serverEngine, &Server::playNote);
    delete(S);
	return app.exec();
}
