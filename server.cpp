#include <QCoreApplication>
#include <QCommandLineParser>
#include "include/network/server.hpp"
#include "include/network/advertizer.hpp"
#include "include/engine/server.hpp"
#include "include/synth/sound_player.hpp"
#include "include/synth/midi_handler.hpp"

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	app.setApplicationName("fanfaresimulator-server");
	app.setApplicationVersion("1.0");

	QCommandLineParser parser;
	parser.setApplicationDescription("FanfareSimulator 2k server");
	parser.addHelpOption();
	parser.addVersionOption();
	parser.addPositionalArgument("audio-file", "The MIDI file to play", "[audio-file]");
	QCommandLineOption playersNbrOption("players-nbr", "Number of players", "n");
	parser.addOption(playersNbrOption);
	parser.process(app);
	const QStringList args = parser.positionalArguments();
	std::string audioFile = args.value(0, "../resources/Movie_Themes_-_Willie_Wonka.mid").toStdString();

	Advertizer advertizer;
	NetworkServer networkServer;

	Partition mainPartition(audioFile);
	//mainPartition.print();

	Sound_player sound_player;
	sound_player.initPupitres(mainPartition);
	//sound_player.testPartition(mainPartition);

	Server serverEngine(networkServer, mainPartition, sound_player);

	// Connect network server & server engine
	QObject::connect(&networkServer, &NetworkServer::helloRecv, &serverEngine,&Server::addClient);
	QObject::connect(&networkServer, &NetworkServer::pupitreChoiceRecv, &serverEngine, &Server::addPupitre);
	QObject::connect(&networkServer, &NetworkServer::noteRecv, &serverEngine, &Server::playNote);
	QObject::connect(&networkServer, &NetworkServer::readyRecv, &serverEngine, &Server::clientReady);

	if (parser.isSet(playersNbrOption)) {
		int playersNbr = parser.value(playersNbrOption).toInt();
		serverEngine.setPlayersNbr(playersNbr);
	}

	return app.exec();
}
