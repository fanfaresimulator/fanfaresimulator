#pragma once

#include "partitionglobale.hpp"

using namespace std;

class State {
private:
    int key;
    double timeLastEvent;
    double blockTime;
public:

    bool signal;
    bool stateChanged;
    vector<NoteGlobale>::iterator itPartitionGlobal;

    int getKey() const;
    double getTimeLastEvent() const;
    double getBlockTime() const;

    void setKey(int newKey);
    void setTimeLastEvent(double newTimeLastEvent);
    void setBlockTime(double newBlockTime);

    double getCurrentTime();
    void reinitialize();
    bool checkStateWithNote(int globalNoteKey, bool globalNoteSignal,
                            double gloablNoteTimeStamp);

};