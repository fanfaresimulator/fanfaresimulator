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
	QCommandLineOption timeScaleOption("time-scale", "Time scale of the partition", "scale");
	parser.addOption(timeScaleOption);
	QCommandLineOption synthGainOption("synth-gain", "Synthesizer audio gain", "gain");
	parser.addOption(synthGainOption);
	QCommandLineOption synthBankOption("synth-bank", "Synthesizer SoundFont2 bank", "path");
	parser.addOption(synthBankOption);
	parser.process(app);
	const QStringList args = parser.positionalArguments();
	std::string audioFile = args.value(0, "../resources/Movie_Themes_-_Willie_Wonka.mid").toStdString();

	Advertizer advertizer;
	NetworkServer networkServer;

	Partition mainPartition(audioFile);
	//mainPartition.print();

	if (parser.isSet(timeScaleOption)) {
		double timeScale = parser.value(timeScaleOption).toDouble();
		mainPartition.scaleTime(timeScale);
	}
	mainPartition.ensureSilenceAtBeginning(3.0); // 3s of silence

	std::string synthBank = "../resources/bank.sf2";
	if (parser.isSet(synthBankOption)) {
		synthBank = parser.value(synthBankOption).toStdString();
	}
	Sound_player sound_player(synthBank);
	sound_player.initPupitres(mainPartition);
	if (parser.isSet(synthGainOption)) {
		double audioGain = parser.value(synthGainOption).toDouble();
		sound_player.setGain(audioGain);
	}
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
