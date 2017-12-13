#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <midifile/MidiFile.h>
#include <midifile/Options.h>

#include "note.hpp"
#include "instrument.hpp"

namespace midi_handler {
  int getTimetype(std::string s);

  double getTime(int ticks, MidiFile& midifile, int timetype);

  std::vector<Note> midi_handler_fromString(std::string s);
}
