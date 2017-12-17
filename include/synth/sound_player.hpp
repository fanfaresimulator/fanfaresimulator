#pragma once

#include "partition.hpp"
#include <fluidsynth.h>

class Sound_player {
private:
    fluid_settings_t* settings;
    fluid_synth_t* synth;
    fluid_audio_driver_t* adriver;

public:
    Sound_player(std::string bankPath);
    ~Sound_player();
    void playNote(Note* note);
    void testPlayer();
    void testPartition(Partition partition);
    void initPupitres(Partition partition);
    void setGain(double gain);
};
