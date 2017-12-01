#include "include/network_server.hpp"
#include "include/synthesizer.hpp"
#include "include/server.hpp"
#include "sound_player.h"
#include "synth/midi_handler.hpp"
#include <QApplication>

#ifdef __unix__
#include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	midi_handler();
	NetworkServer networkServer;

    Sound_player* S = new Sound_player();
    Note* noteon_1  = new Note(1.0,1,0,30,50,0);
    Note* noteoff_1 = new Note(1.0,0,0,30,50,0);

    Note* noteon_2  = new Note(1.0,1,0,90,50,0);
    Note* noteoff_2 = new Note(1.0,0,0,90,50,0);

    for (int i = 0; i < 100; i++) {

        S->playNote(noteon_1);
        /* Sleep for 1 second */
#ifdef __unix__
        sleep(1);
#elif defined(_WIN32) || defined(WIN32)
        Sleep(1000);
#endif
        S->playNote(noteoff_1);

        S->playNote(noteon_2);
        /* Sleep for 1 second */
#ifdef __unix__
        sleep(1);
#elif defined(_WIN32) || defined(WIN32)
        Sleep(1000);
#endif
        S->playNote(noteoff_2);
    }

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
