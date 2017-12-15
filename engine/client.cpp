#include "../include/engine/client.hpp"

Client::Client(QApplication *app, std::string username) : QObject(), app(app),
        username(username) {
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

void Client::setNotesSpeed(float notesSpeed) {
    this->notesSpeed = notesSpeed;
}

void Client::setKeysNumber(int keysNumber) {
    if (keysNumber <= 0 || keysNumber > 9) {
        throw std::invalid_argument("Invalid number of keys");
    }
    this->keysNumber = keysNumber;
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
    //partition.print();

    this->partition = new Partition(partition);
    // generate global partition HERE !
    partitionGlobale = new PartitionGlobale(partition, keysNumber);
    std::cout << "Nombre de notes globales : " << partitionGlobale->getNotes().size() << std::endl;
    //partitionGlobale->print();

    // create State
    vector<NoteGlobale>::iterator it = partitionGlobale->getNotes().begin();
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
    game = new GameWindow(700, 700, *partitionGlobale, keysNumber);
    game->set_speed(notesSpeed);
    game->show();

    pressedNotes = std::vector<Note *>(keysNumber, nullptr);

    sendReady();
}

void Client::start() {
    // start game
    // this blocks, but still processes signals
    std::cout << "Starting the game NOW!" << std::endl;
    connect(game, &GameWindow::keyChanged, this, &Client::pressKey);
    game->run(app);
}

void Client::pressKey(int key, double t, bool pressed) {
    if (key < 0) {
        std::cout << "Invalid key" << std::endl;
        return;
    }
    if (pressed) {
        std::cout << "Pressed key " << key << std::endl;
    } else {
        std::cout << "Released key " << key << std::endl;
    }

    if (pressed) {
        // TODO: improve this
        std::vector<NoteGlobale> notes = partitionGlobale->getNotes();
        NoteGlobale *best = nullptr;
        double bestDiff = std::numeric_limits<double>::infinity();
        for (size_t i = 0; i < notes.size(); ++i) {
            NoteGlobale *n = &notes[i];
            if (n->getKey() != key || n->getSignal() != pressed) {
                continue;
            }

            double dt = std::abs(t - n->getTime());
            if (dt < bestDiff) {
                best = n;
                bestDiff = dt;
            }
        }
        if (best == nullptr) {
            std::cout << "No notes on that key!" << std::endl;
            return;
        }

        Note note = *best->getListOfNotes()->begin();
        pressedNotes[key] = new Note(note);
        sendNote(note);
    } else {
        if (pressedNotes[key] == nullptr) {
            return;
        }
        Note note = *pressedNotes[key];
        note.setSignal(false);
        sendNote(note);
        delete pressedNotes[key];
        pressedNotes[key] = nullptr;
    }
}

// STATE FUNCTIONS

void Client::stateHandleError(){
    vector<NoteGlobale>::iterator it = state->itPartitionGlobal;
    sendNotesAfterError();
    state->itPartitionGlobal =
            partitionGlobale->getNextValidIterator(it, state->getCurrentTime());
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
            partitionGlobale->getNextValidIterator(start, state->getCurrentTime());
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
