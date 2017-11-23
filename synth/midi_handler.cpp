#include "midi_handler.hpp"

using namespace std;

void midi_handler() {
  cout << "Hello world from midi_handler" << endl;
  MidiFile midifile;
  midifile.read("../synth/Movie_Themes_-_Willie_Wonka.mid");
  double tempo = 120.0;
  int tracks = midifile.getTrackCount();
  int TPQ = midifile.getTicksPerQuarterNote();
  cout << "TPQ: " << TPQ << endl;
  if (tracks > 1) {
      cout << "TRACKS: " << tracks << endl;
  }
  for (int track=0; track < tracks; track++) {
      if (tracks > 1) {
          cout << "\nTrack " << track << " has " << midifile.getEventCount(track) << " events" << endl;
       }
       for (int event=0; event < midifile.getEventCount(track); event++) {
            if(!(midifile.getEvent(track, event).isNoteOn() || midifile.getEvent(track, event).isNoteOff())){

              if(midifile.getEvent(track, event).isAftertouch()){
                cout << "Aftertouch :";
              }
              if(midifile.getEvent(track, event).isController()){
                cout << "Controller :";
              }
              if(midifile.getEvent(track, event).isMeta()){
                cout << "Meta :";
              }

              if(midifile.getEvent(track, event).isPitchbend()){
                cout << "Pitchbend :";
              }
              if(midifile.getEvent(track, event).isPressure()){
                cout << "Pressure :";
              }
              if(midifile.getEvent(track, event).isTempo()){
                cout << " Tempo :";
              }
              if(midifile.getEvent(track, event).isTimbre()){
                cout << "Timbre :";
              }

              for (int i=0; i<midifile.getEvent(track, event).size(); i++) {
                          cout << " " << (int)midifile.getEvent(track, event)[i];
                }
              cout << endl;
            }

            else{
              ostringstream note;
              note << midifile.getEvent(track, event).tick * 60.0 / (tempo*TPQ);
              if(midifile.getEvent(track, event).isNoteOn()){
                note << ";1";
              }
              if(midifile.getEvent(track, event).isNoteOff()){
                note << ";0";
              }
              for (int i=1; i<midifile.getEvent(track, event).size(); i++) {  // On commence à 1 car le premier element signifie note on ou noteoff déjà pris en compte
                          note << ";" << (int)midifile.getEvent(track, event)[i];
                }
              cout << "NOTE : "<< note.str() << endl;
            }



            //cout << midifile.getEvent(track, event).getCommandByte() << " ";
            //cout << midifile.getEvent(track, event).getCommandNibble() << " ";
          }

   }
   cout << "Fin midi_handler" << endl;
   cout << endl;

}
