#include "synthesizer.hpp"

#include <stdio.h>


#include "fluidsynth.h"
#include "fluidsynth/settings.h"

void testSynth () {
	
	printf("Hello world from the synth !");
	
	
	
	fluid_settings_t* settings;
    fluid_synth_t* synth;
    settings = new_fluid_settings();
    synth = new_fluid_synth(settings);
    
    
    
    /* Do useful things here */
    delete_fluid_synth(synth);
    delete_fluid_settings(settings);
	
	
	return;
	
}
