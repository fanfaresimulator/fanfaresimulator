
#include <../include/client.hpp>

Client::Client(NetworkClient &network, std::string username) {
    this->net = &network;
    this->username = username;
    sendAddClient(username);
}

vector<Pupitre> Client::pupitreMapToVec(std::map<Pupitre, bool> pmap) {
    vector<Pupitre> pupitreVec = vector<Pupitre>();
    for(pair<Pupitre, bool> p : pmap){
        if(!p.second) continue;
        pupitreVec.push_back(p.first);
    }
    return pupitreVec;
}

void Client::sendAddClient(std::string username) {
    if (username.empty()){
        throw std::invalid_argument("Username null");
    }
    net->sendHello();
}

void Client::choosePupitre(Pupitre p) {
    pupitre = p;
    net->sendPupitreChoice(p);
}

void Client::sendNote(Note note) {
    net->sendNote(note);
}

void Client::sendReady() {
    net->sendReady();
}

// SLOTS

void Client::loadPartition(Partition partition) {
    this->partition = partition;
    // generate global partition HERE !
	partitionGlobale = PartitionGlobale(partition);

    // create State
    vector<NoteGlobale>::iterator it = partitionGlobale.getNotes().begin();
    state = new State(it);

    // load game screen here !
    // need to check with ui team if this block the main thread

    sendReady(); // maybe in ui
}

void Client::forwardPupitreMap(std::map<Pupitre, bool> pmap) {
    PupitreWindow pupitreWindow(pupitreMapToVec(pmap));
    QObject::connect(&pupitreWindow, &PupitreWindow::pupitreChosen, this, &Client::choosePupitre);
    pupitreWindow.show();
}

void Client::start() {
    // start UI game screen here : load global partition etc ...
}

// STATE FUNCTIONS

void Client::stateHandleError(){
    vector<NoteGlobale>::iterator it = state->itPartitionGlobal;
    sendNotesAfterError();
    state->itPartitionGlobal =
            partitionGlobale.getNextValidIterator(it, state->getCurrentTime());
    state->setBlockTime(state->itPartitionGlobal->getTime() - USER_TOLL);
    state->reinitialize();
}


void Client::mainStateFunction() {
    if(state->getCurrentTime() < state->getBlockTime()) return;
    vector<NoteGlobale>::iterator it = state->itPartitionGlobal;
    if(!state->stateChanged){
        sendNotesUntilCurrentTime();
        if(state->getCurrentTime() > it->getTime() + USER_TOLL){
            stateHandleError();
        }
    } else {
        if(state->checkStateWithNote(it->getKey(), it->getSignal(), it->getTime())){
            if(it->getSignal()){
                // always be in GBnote off
                state->itPartitionGlobal++;
                it++;
                sendNotesUntilCurrentTime();
            } else {
                sendNotesUntilCurrentTime();
                state->itPartitionGlobal++;
                it++;
            }
        } else {
            stateHandleError();
        }
    }
}

// CAUTION : send notes just from global note with singal == false

void Client::sendNotesAfterError() {
    vector<NoteGlobale>::iterator start = state->itPartitionGlobal;
    vector<NoteGlobale>::iterator end =
            partitionGlobale.getNextValidIterator(start, state->getCurrentTime());
    for (vector<NoteGlobale>::iterator it = start; it!=end; it++){
        if(it->getSignal()) continue;
        // get a pointer in order to store
        // just unsended note in note global
        vector<Note>* vNote = it->getListOfNotes();
        vector<Note>::iterator start = vNote->begin();
        vector<Note>::iterator end = vNote->end();
        for (vector<Note>::iterator it = start; it!=end; it++){
            Note n = *it;
            sendNote(n);
        }
        vNote->clear();
    }
}

void Client::sendNotesUntilCurrentTime() {
    double currentTime;
    vector<NoteGlobale>::iterator currentGNote = state->itPartitionGlobal;
    if(currentGNote->getSignal()) {
        throw std::invalid_argument("iter in ON !");
    }
    vector<Note>* vNote = state->itPartitionGlobal->getListOfNotes();
    vector<Note>::iterator start = vNote->begin();
    vector<Note>::iterator it;
    for(it = start; it->getTime() <= currentTime; it++ ) {
        Note n = *it;
        sendNote(n);
    }
    vNote->erase(start, it);
}
