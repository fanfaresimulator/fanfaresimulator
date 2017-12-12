#include "../include/engine/client.hpp"

static int TIMER_INTERVAL = 30;

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

    this->partition->print();

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
    state->startChrono();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Client::timerSendNotes);
//    timer->start(TIMER_INTERVAL); // in mili sec
    game->run(app);
}

void Client::pressKey(int key, double t, bool pressed) {

    NoteGlobale nextGlobalNote = state->listOfGNotes.back();
    bool sameKey = (key == nextGlobalNote.getKey());
    bool sameSignal = (pressed == nextGlobalNote.getSignal());
    bool sameTime = ( t < nextGlobalNote.getTime() + USER_TOLL ) && ( t > nextGlobalNote.getTime() - USER_TOLL );
    if (sameKey && sameSignal && sameTime){
        state->listOfGNotes.pop_back();
        timer->start(TIMER_INTERVAL);
    } else {
        if(timer->isActive()) timer->stop();
        // update next global note
        double next_global_note_time = state->listOfGNotes.back().getTime();
        while ( t > next_global_note_time - USER_TOLL){
            state->listOfGNotes.pop_back();
            next_global_note_time = state->listOfGNotes.back().getTime();
        }

        // send all old real notes
        double next_real_note_time = state->listOfNotes.back().getTime();
        while ( t > next_real_note_time ){
            sendNote(state->listOfNotes.back());
            state->listOfNotes.pop_back();
            next_real_note_time = state->listOfNotes.back().getTime();
        }
    }

}

void Client::timerSendNotes() {
    double currTime = state->getCurrentTime();
    double currNoteTime = state->listOfNotes.back().getTime();
    while (currTime > currNoteTime) {
        sendNote(state->listOfNotes.back());
        state->listOfNotes.pop_back();
        currNoteTime = state->listOfNotes.back().getTime();
    }
}

