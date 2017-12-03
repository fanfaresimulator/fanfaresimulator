#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <midifile/MidiFile.h>
#include <midifile/Options.h>

#include "note.hpp"
#include "instrument.hpp"

std::vector<Note> midi_handler(std::string s);
