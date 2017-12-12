#include "../include/engine/state.hpp"

State::State(std::vector<Note> notes, std::vector<NoteGlobale> gNotes) {
    listOfNotes = notes;
    listOfGNotes = gNotes;

    // reverse vecs in order to use pop back method
    std::reverse(listOfNotes.begin(),listOfNotes.end());
    std::reverse(listOfGNotes.begin(),listOfGNotes.end());


}

//// Previous
//State::State(vector<NoteGlobale>::iterator &it) {
//    itPartitionGlobal = it;
//
//    key = 0;
//    stateChanged = false;
//    signal=false;
//    timeLastEvent = 0.0;
//    blockTime = 0.0;
//    stateNeverChanged = true;
//
//}
//
//double State::getBlockTime() const {
//    return blockTime;
//}
//
//int State::getKey() const {
//    return key;
//}
//
//double State::getTimeLastEvent() const {
//    return timeLastEvent;
//}
//
//void State::setBlockTime(double newBlockTime) {
//    if(newBlockTime < blockTime) {
//        throw std::invalid_argument("invalid block time");
//    }
//    blockTime = newBlockTime;
//}
//
//void State::setKey(int newKey) {
//    if(newKey < 0 || newKey > 3){
////        throw std::invalid_argument("invalid key");
//        // DEBUG
//        cout << "INVALID KEY" << endl;
//    }
//    key = newKey;
//}
//
//void State::setTimeLastEvent(double newTimeLastEvent) {
//    if(timeLastEvent > newTimeLastEvent) {
//        throw std::invalid_argument("wrong time last event");
//    }
//    timeLastEvent = newTimeLastEvent;
//}
//
//double State::getCurrentTime() {
//    return (double)t0.elapsed()/1000;
//}
//
//void State::reinitialize() {
//    setKey(0);
//    stateChanged = false;
//}
//
//bool State::checkStateWithNote(int globalNoteKey, bool globalNoteSignal,
//                               double gloablNoteTimeStamp) {
//    cout << "Expected : key, time, sig : " << globalNoteKey << " " << gloablNoteTimeStamp << " " << globalNoteSignal << endl;
//    cout << "actual : key, time, sig : " << getKey() << " " << gloablNoteTimeStamp << " " << globalNoteSignal << endl;
//    bool keyEquals = (getKey() == globalNoteKey);
//    bool signalEquals = (signal == globalNoteSignal);
//    bool timesEquals;
//    if (globalNoteSignal){
//        timesEquals = (getTimeLastEvent() >= gloablNoteTimeStamp - USER_TOLL)&&
//                      (getTimeLastEvent() <= gloablNoteTimeStamp + USER_TOLL);
//    }
//    timesEquals = (getTimeLastEvent() >= gloablNoteTimeStamp - USER_TOLL) &&
//            (getTimeLastEvent() <= gloablNoteTimeStamp + USER_TOLL);
//
//    return keyEquals && signalEquals && timesEquals;
//
//}
//
//void State::startChrono() {
//    t0.start();
//}
//
