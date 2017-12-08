#include "../gui/game_window.hpp"
#include "../include/client.hpp"

Client::Client(QApplication *app, std::string username) : QObject() {
    this->app = app;
    this->username = username;

    std::cout << "Discovering server..." << std::endl;
    this->discoverer = new Discoverer();
    connect(discoverer, &Discoverer::discovered, this, &Client::connectToServer);
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
    this->partition = partition;
    // generate global partition HERE !
    partitionGlobale = PartitionGlobale(partition);
    std::cout << "Nombre de notes globales : " << partitionGlobale.getNotes().size() << std::endl;

    // create State
    vector<NoteGlobale>::iterator it = partitionGlobale.getNotes().begin();
    state = new State(it);

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
    game = new GameWindow(700, 700, partitionGlobale);
    game->show();

    sendReady();
}

void Client::start() {
    // start game
    // this blocks, but still processes signals
    std::cout << "Starting the game NOW!" << std::endl;
    connect(game, &GameWindow::keyChanged, this, &Client::pressKey);
    game->run(app);
}

void Client::pressKey(int key, int t, bool pressed) {
    if (key < 0) {
        std::cout << "Pressed/released invalid key" << std::endl;
        return;
    }
    std::cout << "Pressed/released key " << key << std::endl;

    // TODO
    sendNote(*partition.getNotes().begin());
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
    double currentTime = state->getCurrentTime();
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
