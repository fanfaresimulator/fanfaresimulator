#include "note.hpp"
#include <fluidsynth.h>

#ifndef FANFARESIMULATOR_SOUND_PLAYER_H
#define FANFARESIMULATOR_SOUND_PLAYER_H



class Sound_player {

private:

    fluid_settings_t* settings;
    fluid_synth_t* synth;
    fluid_audio_driver_t* adriver;

public:
    Sound_player();

    ~Sound_player();

    void playNote(Note* note);

    void testPlayer();
};



#endif //FANFARESIMULATOR_SOUND_PLAYER_H
