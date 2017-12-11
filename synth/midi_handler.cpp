#include "../include/midi_handler.hpp"

std::vector<Note> midi_handler::midi_handler_fromString(std::string s) {
  MidiFile midifile;
  midifile.read(s);
  midifile.sortTracks();
  midifile.absoluteTicks();

  std::vector<Note> listOfNotes;

  int tracks = midifile.getTrackCount();
  for (int track=0; track < tracks; track++) {
    int instru = -1;
    for (int event=0; event < midifile.getEventCount(track); event++) {
      MidiEvent &e = midifile.getEvent(track, event);
      if (e.isTimbre()) {
        instru = (int)e[1];
        //cout << "Timbre : " << GMinstrument[(int)e[1]] << " " << (int)e[1] << endl;
      } else if (e.isNoteOn() || e.isNoteOff()) {
        Note n = Note(midifile.getTimeInSeconds(track, event), e.isNoteOn(),
          Pupitre(track, Instrument(instru)), (int)e[1], (int)e[2]);
        listOfNotes.push_back(n);
      }
    }
  }

  return listOfNotes;
}
