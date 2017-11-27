#include "include/network_server.hpp"
#include "synth/synthesizer.hpp"
#include "synth/midi_handler.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	NetworkServer serv;

	midi_handler();
	testSynth();

	return app.exec();
}
