#include "include/network_server.hpp"
#include "include/synthesizer.hpp"
#include "include/server.hpp"
#include <QApplication>


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
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
//
//	QObject::connect(&serverEngine, &Server::playNote,
//					 &synthesizer, &Synthesizer::playNote);
//
//	QObject::connect(&serverEngine, &Server::requestPartiton,
//					 &synthesizer, &Synthesizer::getPartition);
//
//	QObject::connect(&synthesizer, &Synthesizer::sendPartition,
//					 &serverEngine, &Server::sendPartition);

	return app.exec();
}
