#include "include/network_server.hpp"
#include "include/synthesizer.hpp"
#include "include/server.hpp"
#include "synth/midi_handler.hpp"
#include "include/synthesizer.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	midi_handler();
	testSynth();

	NetworkServer networkServer;

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
//

    /* CONNECTS synthesizer & server engine */

//	QObject::connect(&serverEngine, &Server::playNote,
//					 &synthesizer, &Synthesizer::playNote);
//
//	QObject::connect(&serverEngine, &Server::requestPartition,
//					 &synthesizer, &Synthesizer::getPartition);
//
//	QObject::connect(&synthesizer, &Synthesizer::sendPartition,
//					 &serverEngine, &Server::sendPartition);

//	QObject::connect(&serverEngine, &Server::requestInstrumentList,
//					 &synthesizer, &Synthesizer::getInstrumentList);
//
//	QObject::connect(&synthesizer, &Synthesizer::sendInstrumentList,
//					 &serverEngine, &Server::instrumentMapInit);

	return app.exec();
}
