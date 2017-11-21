#include <iostream>

#include "synth/synthesizer.hpp"
#include "synth/midi_handler.hpp"

int main(int argc, char *argv[])
{
	// QApplication app(argc, argv);

	// TestWindow window;

	// window.show();
	midi_handler();
	testSynth();

	// return app.exec();
	return 0;
}
