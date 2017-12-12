#pragma once

#include "synth/partitionglobale.hpp"
#include <QObject>
#include <QTime>
#include "../synth/note.hpp"
#include "../synth/noteglobale.hpp"
#include <algorithm>

using namespace std;

class State : public QObject {
private:
    int key;
    double timeLastEvent;
    double blockTime;
    QTime t0;


public:
    std::vector<Note> listOfNotes;
    std::vector<NoteGlobale> listOfGNotes ;

    bool signal;
    bool stateChanged;
    bool stateNeverChanged;
    vector<NoteGlobale>::iterator itPartitionGlobal;

    // methods
    State(vector<NoteGlobale>::iterator& it);

    State(std::vector<Note> notes, std::vector<NoteGlobale> gNotes);

    void startChrono();
    double getCurrentTime();
//    int getKey() const;
//    double getTimeLastEvent() const;
//    double getBlockTime() const;
//
//    void setKey(int newKey);
//    void setTimeLastEvent(double newTimeLastEvent);
//    void setBlockTime(double newBlockTime);
//
//    double getCurrentTime();
//    void reinitialize();
//    bool checkStateWithNote(int globalNoteKey, bool globalNoteSignal,
//                            double gloablNoteTimeStamp);

};
