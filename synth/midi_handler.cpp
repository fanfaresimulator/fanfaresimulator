#include "../include/midi_handler.hpp"

#define TICK 1            // time units are MIDI file ticks (absolute)
#define BEAT 2            // time units are Beats (quarter note, absolute)
#define SEC  3            // time units are seconds (absolute)
#define MSEC 4            // time units are millisecodns (absolute)

int midi_handler::getTimetype(std::string s){

  Options opts;
  opts.define("t|ticks|tick=b",                    "display time in ticks");
  opts.define("s|sec|second|seconds=b",            "display time in seconds");
  opts.define("m|msec|millisecond|milliseconds=b", "display time in msec");
  opts.define("b|beat|beats=b",                    "display time in beats");

  char* argvalues[1];

  argvalues[0] = new char[s.length()+1];
  for (int i = 0; i < s.length(); i++){
    argvalues[0][i] = s[i];
  }
  argvalues[0][s.length()] = '\0';
  opts.process(1, argvalues);

  int tickQ = opts.getBoolean("ticks");
  int secQ  = opts.getBoolean("seconds");
  int msecQ = opts.getBoolean("milliseconds");
  int beatQ = opts.getBoolean("beats");

  if (tickQ) {
     return TICK;
  } else if (beatQ) {
     return BEAT;
  } else if (secQ) {
     return SEC;
  } else if (msecQ) {
     return MSEC;
  } else {
     return BEAT;
  }
  return SEC;
}

double midi_handler::getTime(int ticks, MidiFile& midifile, int timetype) {
   int tpq = midifile.getTicksPerQuarterNote();
   switch (timetype) {
      case TICK:
         return ticks;
      case BEAT:
         return (double)ticks/tpq;
      case SEC:
         return midifile.getTimeInSeconds(ticks);
      case MSEC:
         return 1000 * midifile.getTimeInSeconds(ticks);
   }
   return 0.0;
}

std::vector<Note> midi_handler::midi_handler_fromString(std::string s) {

  MidiFile midifile;
  midifile.read(s);

  std::vector<Note> listOfNotes;
  int timetype = getTimetype(s);

  int tracks = midifile.getTrackCount();
  for (int track=0; track < tracks; track++) {
       int instru = -1;
       for (int event=0; event < midifile.getEventCount(track); event++) {
            if(!(midifile.getEvent(track, event).isNoteOn() || midifile.getEvent(track, event).isNoteOff())){
              if(midifile.getEvent(track, event).isTimbre()){
                instru = (int)midifile.getEvent(track, event)[1];
                //cout << "Timbre : " << GMinstrument[(int)midifile.getEvent(track, event)[1]] << " " << (int)midifile.getEvent(track, event)[1] << endl;
              }
            }

            else{
              Note n = Note(getTime(midifile.getEvent(track, event).tick, midifile, timetype),
                            (int)midifile.getEvent(track, event).isNoteOn(),
                           Pupitre(track, Instrument(instru)),
                             (int)midifile.getEvent(track, event)[1],
                           (int)midifile.getEvent(track, event)[2]);
             listOfNotes.push_back(n);
            }
      }
   }
   return listOfNotes;
}
