#pragma once

#include "partition.hpp"
#include <fluidsynth.h>

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
    void testPartition(std::string filename);
    void initPupitres(Partition partition);
};
