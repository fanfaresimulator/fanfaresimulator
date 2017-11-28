#pragma once

#include <fluidsynth.h>

void testSynth();


/*
#pragma once

#include <iostream>
#include "instrument.hpp"
#include "note.hpp"
#include "partition.hpp"
#include <fluidsynth.h>

void testSynth();

class Synthesizer {
private:
    Partition mainPartition;
    fluid_synth_t *synth;
    fluid_settings_t *settings;
    fluid_audio_driver_t *adriver;


public:


    Synthesizer(Partition mainPartition);

    ~Synthesizer();

    Partition getPartition(Instrument instrument);

    void playNote(Note note);

    void stopNote(Note note);

    void playJingle();

    void mapChannels();

    void setPartition();
};
*/
