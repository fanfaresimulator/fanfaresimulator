#include "../include/engine/client.hpp"

static int TIMER_INTERVAL = 50;

Client::Client(QApplication *app, std::string username) : QObject(), app(app),
        username(username) {
    std::cout << "Discovering server..." << std::endl;
    this->discoverer = new Discoverer();
    connect(discoverer, &Discoverer::discovered, this, &Client::connectToServer);
//    timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &Client::mainStateFunction);
}

vector<Pupitre> Client::pupitreMapToVec(std::map<Pupitre, bool> pmap) {
    vector<Pupitre> pupitreVec = vector<Pupitre>();
    for(pair<Pupitre, bool> p : pmap){
        if (p.second) continue;
        pupitreVec.push_back(p.first);
    }
    return pupitreVec;
}

void Client::sendAddClient(std::string username) {
    if (username.empty()) {
        throw std::invalid_argument("Username null");
    }
    net->sendHello();
}

void Client::choosePupitre(Pupitre p) {
    pupitre = new Pupitre(p);
    net->sendPupitreChoice(p);
}

void Client::sendNote(Note note) {
    net->sendNote(note);
}

void Client::sendReady() {
    net->sendReady();
}

// SLOTS

void Client::connectToServer(QHostAddress addr, quint16 port) {
    if (net != NULL) {
        return;
    }

    std::cout << "Connecting to " << addr.toString().toStdString() << ":" << port << std::endl;

    net = new NetworkClient(addr, port, username);
    connect(net, &NetworkClient::pupitresRecv, this, &Client::forwardPupitreMap);
    connect(net, &NetworkClient::partitionRecv, this, &Client::loadPartition);
    connect(net, &NetworkClient::startRecv, this, &Client::start);

    sendAddClient(username);
}

void Client::forwardPupitreMap(std::map<Pupitre, bool> pmap) {
    pupitreWindow = new PupitreWindow(pupitreMapToVec(pmap));
    connect(pupitreWindow, &PupitreWindow::pupitreChosen, this, &Client::choosePupitre);
    pupitreWindow->show();
}

void Client::loadPartition(Partition partition) {
    this->partition = new Partition(partition);


    // generate global partition HERE !
    partitionGlobale = new PartitionGlobale(partition, KEYS_NUMBER);
    std::cout << "Nombre de notes globales : " << partitionGlobale->getNotes().size() << std::endl;
    partitionGlobale->print();

    // create State
    vector<NoteGlobale>::iterator it = partitionGlobale->getNotes().begin();
    state = new State(partition.getNotes(), partitionGlobale->getNotes());

    // for testing
    /*std::vector<string> list;
    list.push_back("1000");
    list.push_back("0");
    list.push_back("U");
    list.push_back("1500");
    list.push_back("0");
    list.push_back("D");
    list.push_back("3000");
    list.push_back("1");
    list.push_back("U");
    list.push_back("5000");
    list.push_back("1");
    list.push_back("D");
    game = new GameWindow(700, 700, list);*/

    // create game screen
    game = new GameWindow(700, 700, *partitionGlobale, KEYS_NUMBER);
    game->show();

    sendReady();
}

void Client::start() {
    // start game
    // this blocks, but still processes signals
    std::cout << "Starting the game NOW!" << std::endl;
    connect(game, &GameWindow::keyChanged, this, &Client::pressKey);
    // engine
//    state->startChrono();
//    timer->start(TIMER_INTERVAL); // in mili sec
    game->run(app);
}

void Client::pressKey(int key, double t, bool pressed) {
//    if (t < state->getBlockTime()) {
//        cout << "KEYBOARD BLOCKED" << endl;
//        return;
//    }
//    state->stateChanged = true;
//    state->stateNeverChanged = false;
//    state->setKey(key);
//    state->setTimeLastEvent(t);
//    state->signal = pressed;

//    cout <<"SEG 0" << endl;
//    double next_gnote_time = state->listOfGNotes.back().getTime();
//    cout <<"SEG 1" << endl;
//    if (t < next_gnote_time - USER_TOLL) return;
//
//    if ( t > next_gnote_time + USER_TOLL) {
//        cout <<"SEG 2" << endl;
//        double new_gnote_time = next_gnote_time;
//        cout <<"SEG 3" << endl;
//        while (t > new_gnote_time + USER_TOLL){
//            state->listOfGNotes.pop_back();
//            new_gnote_time = state->listOfGNotes.back().getTime();
//        }
//        cout <<"SEG 4" << endl;
//        double new_real_note_time = state->listOfNotes.back().getTime();
//        cout <<"SEG 5" << endl;
//        while(new_gnote_time > new_real_note_time){
//            sendNote(state->listOfNotes.back());
//            state->listOfNotes.pop_back();
//        }
//        cout <<"SEG 6" << endl;
//        return;
//    }
//    cout <<"SEG 7" << endl;
//    state->listOfGNotes.pop_back();
//    cout <<"SEG 8" << endl;
//    double curr_real_note_time = state->listOfNotes.back().getTime();
//    cout <<"SEG 9" << endl;
//    while(curr_real_note_time < t){
//        sendNote(state->listOfNotes.back());
//        state->listOfNotes.pop_back();
//    }
//    cout <<"SEG 10" << endl;

//    double next_gnote_time = state->listOfGNotes.back().getTime();
//    double new_gnote_time = next_gnote_time;
//    cout <<"SEG 3" << endl;
//    while (t > new_gnote_time + USER_TOLL){
//        state->listOfGNotes.pop_back();
//        new_gnote_time = state->listOfGNotes.back().getTime();
//    }
    double curr_real_note_time = state->listOfNotes.back().getTime();
    while(curr_real_note_time < t){
        sendNote(state->listOfNotes.back());
        state->listOfNotes.pop_back();
    }

}

//// STATE FUNCTIONS
//
//void Client::stateHandleError(){
//    cout <<"SEG 3" << endl;
//    vector<NoteGlobale>::iterator it = state->itPartitionGlobal;
//    cout <<"SEG 3.1" << endl;
//    sendNotesAfterError();
//    cout <<"SEG 3.2" << endl;
//    state->itPartitionGlobal =
//            partitionGlobale->getNextValidIterator(it, state->getCurrentTime());
//    cout <<"SEG 3.3" << endl;
//    state->setBlockTime(state->itPartitionGlobal->getTime());
//    cout <<"SEG 3.4" << endl;
//    state->reinitialize();
//    cout <<"SEG 3.5" << endl;
//}
//
//
//void Client::mainStateFunction() {
//    cout << "current time = " << state->getCurrentTime();
//    if(state->stateNeverChanged) {
//        cout <<"state never changed !" << endl;
//        return;
//    }
//    if(state->getCurrentTime() < state->getBlockTime()){
//        cout << "already BLOCKED - time == " << state->getBlockTime() << endl;
//        return;
//    }
//
//    vector<NoteGlobale>::iterator it = state->itPartitionGlobal;
//    cout <<"SEG 0" << endl;
//    if(!state->stateChanged){
//        cout << "state didnt changed" << endl;
//        if(state->getCurrentTime() > it->getTime()){
//            stateHandleError();
//        }
//        cout <<"SEG 1.1" << endl;
//        sendNotesUntilCurrentTime();
//        cout <<"SEG 1.2" << endl;
//    } else {
//        cout <<"SEG 2" << endl;
//        if(state->checkStateWithNote(it->getKey(), it->getSignal(), it->getTime())){
//            cout <<"SEG 2.1" << endl;
//            if(it->getSignal()){
//                // always be in GBnote off
//                cout <<"SEG 2.1.1" << endl;
//                state->itPartitionGlobal++;
//                it++;
//                cout <<"SEG 2.1.2" << endl;
//                sendNotesUntilCurrentTime();
//                cout <<"SEG 2.1.3" << endl;
//            } else {
//                cout <<"SEG 2.2.1" << endl;
//                sendNotesUntilCurrentTime(); // change here send ALL notes
//                cout <<"SEG 2.2.2" << endl;
//                state->itPartitionGlobal++;
//                it++;
//            }
//        } else {
//            cout <<"SEG 2.3.1" << endl;
//            stateHandleError();
//            cout <<"SEG 2.3.2" << endl;
//        }
//    }
//}
//
//// CAUTION : send notes just from global note with singal == false
//
//void Client::sendNotesAfterError() {
//    cout <<"SEG 4" << endl;
//    vector<NoteGlobale>::iterator start = state->itPartitionGlobal;
//    cout <<"SEG 4.1" << endl;
//    vector<NoteGlobale>::iterator end =
//            partitionGlobale->getNextValidIterator(start, state->getCurrentTime());
//    cout <<"SEG 4.2" << endl;
//    for (vector<NoteGlobale>::iterator it = start; it!=end; it++){
//        cout <<"SEG 4.3*" << endl;
//        if(it->getSignal()) continue;
//        // get a pointer in order to store
//        // just unsended note in note global
//        vector<Note>* vNote = it->getListOfNotes();
//        cout <<"SEG 4.3*.1" << endl;
//        vector<Note>::iterator start = vNote->begin();
//        cout <<"SEG 4.3*.2" << endl;
//        vector<Note>::iterator end = vNote->end();
//        cout <<"SEG 4.3*.3" << endl;
//        for (vector<Note>::iterator it = start; it!=end; it++){
//            Note n = *it;
//            cout <<"SEG 4.3*.3.1" << endl;
//            sendNote(n);
//            cout <<"SEG 4.3*.3.2" << endl;
//        }
//        cout <<"SEG 4.3*.4" << endl;
//        vNote->clear();
//        cout <<"SEG 4.3*.5" << endl;
//    }
//}
//
//void Client::sendNotesUntilCurrentTime() {
//    cout <<"SEG 1.1.1" << endl;
//    vector<NoteGlobale>::iterator currentGNote = state->itPartitionGlobal;
//    cout <<"SEG 1.1.2" << endl;
//    if(currentGNote->getSignal()) {
//        throw std::invalid_argument("iter in ON !");
//    }
//    cout <<"SEG 1.1.3" << endl;
//    vector<Note>* vNote = state->itPartitionGlobal->getListOfNotes();
//    vector<Note>::iterator start = vNote->begin();
//    vector<Note>::iterator it;
//    cout <<"SEG 1.1.4" << endl;
//    double currentTime = state->getCurrentTime();
//    cout <<"SEG 1.1.5" << endl;
//    for(it = start; it->getTime() <= currentTime; it++ ) {
//        cout <<"SEG 1.1.5*" << endl;
//        Note n = *it;
//        sendNote(n);
//    }
//    cout <<"SEG 1.1.6" << endl;
//    vNote->erase(start, it);
//}
