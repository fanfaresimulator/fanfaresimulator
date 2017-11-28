#include <iostream>
#include <sstream>
#include <iomanip>
#include <midifile/MidiFile.h>
#include <midifile/Options.h>
#include <note.hpp>
#include "midi_handler.hpp"


using namespace std;

#define TICK 1            /* time units are MIDI file ticks (absolute)     */
#define BEAT 2            /* time units are Beats (quarter note, absolute) */
#define SEC  3            /* time units are seconds (absolute)             */
#define MSEC 4            /* time units are millisecodns (absolute)        */


double getTime(int ticks, MidiFile& midifile, int timetype) {
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

const char *GMinstrument[128] = {
   "acpiano",   "britepno",  "synpiano",  "honkytonk", "epiano1",   "epiano2",
   "hrpschrd",  "clavinet",  "celeste",   "glocken",   "musicbox",  "vibes",
   "marimba",   "xylophon",  "tubebell",  "santur",    "homeorg",   "percorg",
   "rockorg",   "churchorg", "reedorg",   "accordn",   "harmonica", "concrtna",
   "nyguitar",  "acguitar",  "jazzgtr",   "cleangtr",  "mutegtr",   "odguitar",
   "distgtr",   "gtrharm",   "acbass",    "fngrbass",  "pickbass",  "fretless",
   "slapbas1",  "slapbas2",  "synbass1",  "synbass2",  "violin",    "viola",
   "cello",     "contraba",  "marcato",   "pizzcato",  "harp",      "timpani",
   "marcato",   "slowstr",   "synstr1",   "synstr2",   "choir",     "doo",
   "voices",    "orchhit",   "trumpet",   "trombone",  "tuba",      "mutetrum",
   "frenchorn", "hitbrass",  "synbras1",  "synbras2",  "sprnosax",  "altosax",
   "tenorsax",  "barisax",   "oboe",      "englhorn",  "bassoon",   "clarinet",
   "piccolo",   "flute",     "recorder",  "woodflut",  "bottle",    "shakazul",
   "whistle",   "ocarina",   "sqrwave",   "sawwave",   "calliope",  "chiflead",
   "charang",   "voxlead",   "lead5th",   "basslead",  "fantasia",  "warmpad",
   "polysyn",   "ghostie",   "bowglass",  "metalpad",  "halopad",   "sweeper",
   "aurora",    "soundtrk",  "crystal",   "atmosphr",  "freshair",  "unicorn",
   "sweeper",   "startrak",  "sitar",     "banjo",     "shamisen",  "koto",
   "kalimba",   "bagpipes",  "fiddle",    "shannai",   "carillon",  "agogo",
   "steeldrum", "woodblock", "taiko",     "toms",      "syntom",    "revcymb",
   "fx-fret",   "fx-blow",   "seashore",  "jungle",    "telephone", "helicptr",
   "applause",  "ringwhsl"
};



void midi_handler() {
  //cout << "Hello world from midi_handler" << endl;
  MidiFile midifile;
  midifile.read("../resources/Movie_Themes_-_Willie_Wonka.mid");

  Options opts;
  opts.define("t|ticks|tick=b",                    "display time in ticks");
  opts.define("s|sec|second|seconds=b",            "display time in seconds");
  opts.define("m|msec|millisecond|milliseconds=b", "display time in msec");
  opts.define("b|beat|beats=b",                    "display time in beats");

  char* argvalues[1];
  std::string s = "../resources/Movie_Themes_-_Willie_Wonka.mid";
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

  int timetype = SEC;

  if (tickQ) {
     timetype = TICK;
  } else if (beatQ) {
     timetype = BEAT;
  } else if (secQ) {
     timetype = SEC;
  } else if (msecQ) {
     timetype = MSEC;
  } else {
     timetype = BEAT;
  }

  int tracks = midifile.getTrackCount();
  //int TPQ = midifile.getTicksPerQuarterNote();
  // cout << "TPQ: " << TPQ << endl;
  // if (tracks > 1) {
  //     cout << "TRACKS: " << tracks << endl;
  // }
  // cout << endl;

  for (int track=0; track < tracks; track++) {
      // if (tracks > 1) {
      //     cout << "\nTrack " << track << " has " << midifile.getEventCount(track) << " events" << endl;
      //  }
      int instru;

       for (int event=0; event < midifile.getEventCount(track); event++) {


            if(!(midifile.getEvent(track, event).isNoteOn() || midifile.getEvent(track, event).isNoteOff())){

              // if(midifile.getEvent(track, event).isAftertouch()){
              //   cout << "Aftertouch :";
              // }
              // if(midifile.getEvent(track, event).isController()){
              //   cout << "Controller :";
              // }
              // if(midifile.getEvent(track, event).isMeta()){
              //   cout << "Meta :";
              // }
              //
              // if(midifile.getEvent(track, event).isPitchbend()){
              //   cout << "Pitchbend :";
              // }
              // if(midifile.getEvent(track, event).isPressure()){
              //   cout << "Pressure :";
              // }
              // if(midifile.getEvent(track, event).isTempo()){
              //   cout << " Tempo :";
              // }
              if(midifile.getEvent(track, event).isTimbre()){
                instru = (int)midifile.getEvent(track, event)[1];
                //cout << "Timbre : " << GMinstrument[(int)midifile.getEvent(track, event)[1]] << " " << (int)midifile.getEvent(track, event)[1] << endl;
              }

              // for (int i=0; i<midifile.getEvent(track, event).size(); i++) {
              //             cout << " " << (int)midifile.getEvent(track, event)[i];
              //   }
              //cout << endl;
            }

            else{
              Note n;
              ostringstream note;
              //note << midifile.getEvent(track, event).tick * 60.0 / (tempo*TPQ) << ";" << instru << ";" << track;
              note << getTime(midifile.getEvent(track, event).tick, midifile, timetype)<< " " << instru << " " << track;

              if(midifile.getEvent(track, event).isNoteOn()){
                note << " 1";
              }
              if(midifile.getEvent(track, event).isNoteOff()){
                note << " 0";
              }
              for (int i=1; i<midifile.getEvent(track, event).size(); i++) {  // On commence à 1 car le premier element signifie note on ou noteoff déjà pris en compte
                          note << " " << (int)midifile.getEvent(track, event)[i];
                }
              cout << note.str() << endl;
            }

            //cout << midifile.getEvent(track, event).getCommandByte() << " ";
            //cout << midifile.getEvent(track, event).getCommandNibble() << " ";
          }

   }

}
