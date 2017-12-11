#include <stdio.h>
#ifdef __unix__
#include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif
#include "../include/synth/sound_player.hpp"
#include "../include/synth/note.hpp"

#define SOUNDFONT_PATH "../resources/sf.sf2"
//#define SOUNDFONT_PATH "../resources/GeneralUser GS 1.471/GeneralUser GS v1.471.sf2"
#define SYNTH_GAIN 2
//#define SYNTH_GAIN 1

// Fuck you windows
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
void usleep(__int64 usec)
{
    HANDLE timer;
    LARGE_INTEGER ft;

    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL);
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
    WaitForSingleObject(timer, INFINITE);
    CloseHandle(timer);
}
#endif

Sound_player::Sound_player() {
    printf("Created the Synth !\n");
    settings = new_fluid_settings();
    synth = new_fluid_synth(settings);

    /* Set the synthesizer settings, if necessary */
#ifdef __linux__
            fluid_settings_setstr(settings, "audio.driver", "pulseaudio"); // à changer
#endif
    fluid_synth_sfload(synth, SOUNDFONT_PATH, 1);

    adriver = new_fluid_audio_driver(settings, synth);

    fluid_settings_setnum(settings, "synth.gain", SYNTH_GAIN);

}

Sound_player::~Sound_player() {
    delete_fluid_audio_driver(adriver);
    delete_fluid_settings(settings);
    delete_fluid_synth(synth);
}

void Sound_player::initPupitres(Partition partition) {
    std::vector<Pupitre> pupitres = partition.getPupitre();
    int instrument, track ;
    for(size_t i=0; i<pupitres.size(); i++){
        track = pupitres[i].getTrack();
        instrument = pupitres[i].getInstrument().getNumber();
        // Chaque track joue dans un channel égal à son track et en utilisant le Soundfont correspondant à son instrument
        fluid_synth_program_change(synth, track, instrument);
    }
};

void Sound_player::playNote(Note* note) {
    if (note->getSignal()) {
        fluid_synth_noteon(synth, note->getTrack(), note->getKey(), note->getVelocity());
    } else {
        fluid_synth_noteoff(synth, note->getTrack(), note->getKey());
    }
}

void Sound_player::testPlayer() {
    Note* noteon_1  = new Note(1.0,1,Pupitre(0,Instrument(30)),50,0);
    Note* noteoff_1 = new Note(1.0,0,Pupitre(0,Instrument(30)),50,0);

    Note* noteon_2  = new Note(1.0,1,Pupitre(0,Instrument(90)),50,0);
    Note* noteoff_2 = new Note(1.0,0,Pupitre(0,Instrument(90)),50,0);

    for (int i = 0; i < 100; i++) {

        playNote(noteon_1);
        /* Sleep for 1 second */
#ifdef __unix__
        sleep(1);
#elif defined(_WIN32) || defined(WIN32)
        Sleep(1000);
#endif
        playNote(noteoff_1);

        playNote(noteon_2);
        /* Sleep for 1 second */
#ifdef __unix__
        sleep(1);
#elif defined(_WIN32) || defined(WIN32)
        Sleep(1000);
#endif
        playNote(noteoff_2);
    }
}

void Sound_player::testPartition(Partition partition) {
    initPupitres(partition);

    std::vector<Note> notes = partition.getNotes();
    for (size_t i = 0; i < notes.size(); i++) {
        playNote(&notes[i]);
        int dt = 1000000 * (notes[i + 1].getTime() - notes[i].getTime());
        usleep(dt);
    }
}
