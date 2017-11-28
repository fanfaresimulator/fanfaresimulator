#include "include/network_server.hpp"
#include "include/synthesizer.hpp"
#include "include/server.hpp"
#include "synth/midi_handler.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
midi_handler();
testSynth();

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
