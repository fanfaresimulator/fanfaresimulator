#include "include/network/server.hpp"
#include "include/network/advertizer.hpp"
#include "include/synthesizer.hpp"
#include "include/server.hpp"
#include "synth/midi_handler.hpp"
#include "include/synthesizer.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	//midi_handler();
	//testSynth();

	Advertizer advertizer;
	NetworkServer networkServer;

//	Synthesizer synthesizer;
//	Server serverEngine(networkServer, synthesizer);
//
//	QObject::connect(&networkServer, &NetworkServer::helloRecv,
//					 &serverEngine, &Server::addClient);
//
//	QObject::connect(&networkServer, &NetworkServer::instrumentChoiceRecv,
//					 &serverEngine, &Server::addInstrument);
//
//	QObject::connect(&networkServer, &NetworkServer::noteRecv,
//					 &serverEngine, &Server::playNote);

	return app.exec();
}
