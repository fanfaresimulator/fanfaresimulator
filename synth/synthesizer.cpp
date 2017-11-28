#include <stdio.h>
#include <fluidsynth.h>
#include <fluidsynth/settings.h>

#ifdef __unix__
#include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include "synthesizer.hpp"

void testSynth() {
	printf("Hello world from the synth !\n");

	fluid_settings_t* settings;
	fluid_synth_t* synth;
	fluid_audio_driver_t* adriver;
	settings = new_fluid_settings();
	/* Set the synthesizer settings, if necessary */
	synth = new_fluid_synth(settings);
#ifdef __linux__
	fluid_settings_setstr(settings, "audio.driver", "pulseaudio"); // à changer
#endif

	adriver = new_fluid_audio_driver(settings, synth);

	fluid_synth_sfload(synth, "../resources/sf.sf2", 1);
	fluid_settings_setnum(settings, "synth.gain", 2);
	fluid_synth_program_change(synth, 0, 16); // 40 = violon dans la bank0. On reste dans la bank 0. 16 = tonewheel organ ooooh yeah -> Cory Henry/Jimmy Smith inside

	int key;
	for (int i = 0; i < 10002; i++) {
		/* Generate a random key */
		key = 60+i;
		/* Play a note */
		fluid_synth_noteon(synth, 0, key, 80);
		fluid_synth_noteon(synth, 0, key + 4, 80); // une petite tierce
		/* Sleep for 1 second */
#ifdef __unix__
		sleep(1);
#elif defined(_WIN32) || defined(WIN32)
		Sleep(1000);
#endif
		/* Stop the note */
		fluid_synth_noteoff(synth, 0, key);
		fluid_synth_noteoff(synth, 0, key + 4);
	}

	/* Do useful things here */
	delete_fluid_audio_driver(adriver);
	delete_fluid_synth(synth);
	delete_fluid_settings(settings);
}
