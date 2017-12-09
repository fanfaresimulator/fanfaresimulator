#include <stdio.h>
#ifdef __unix__
#include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif
#include "../include/sound_player.hpp"
#include "../include/note.hpp"


Sound_player::Sound_player() {
    printf("Created the Synth !\n");
    settings = new_fluid_settings();
    synth = new_fluid_synth(settings);

    /* Set the synthesizer settings, if necessary */
#ifdef __linux__
            fluid_settings_setstr(settings, "audio.driver", "pulseaudio"); // à changer
#endif
    fluid_synth_sfload(synth, "../resources/sf.sf2", 1);

    adriver = new_fluid_audio_driver(settings, synth);

    fluid_settings_setnum(settings, "synth.gain", 2);

}

Sound_player::~Sound_player() {
    delete_fluid_audio_driver(adriver);
    delete_fluid_settings(settings);
    delete_fluid_synth(synth);
}

void Sound_player::initPupitres(Partition partition){
    std::vector<Pupitre> pupitres = partition.getPupitre();
    int instrument, track ;
    for(int i=0; i<pupitres.size(); i++){
        track = pupitres[i].getTrack();
        instrument = pupitres[i].getInstrument().getNumber();
        //Chaque track joue dans un channel égal à son track et en utilisant le Soundfont correspondant à son instrument;
        fluid_synth_program_change(synth, track , instrument);
        }
};

void Sound_player::playNote(Note* note){
    if(note->getSignal()){
        fluid_synth_noteon(synth, note->getTrack(), note->getKey(), note->getVelocity());
    }
    else {
        fluid_synth_noteoff(synth, note->getTrack(),note->getVelocity ());
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


void Sound_player::testPartition(std::string filename) {
    Partition partition = Partition(filename);
    initPupitres(partition);

    for (int i = 0; i < partition.getNotes().size() - 1; i++) {
        playNote(&partition.getNotes()[i]);
        // Sleep for 1 second
        usleep(1000000 * (partition.getNotes()[i + 1].getTime() - partition.getNotes()[i].getTime()));
    }

}
