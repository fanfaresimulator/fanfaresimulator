
#include <../include/client.hpp>

Client::Client(NetworkClient &network, std::string username) {
    this->net = &network;
    this->username = username;

}


void Client::sendAddClient(std::string username) {
    if (username.empty()){
        throw std::invalid_argument("Username null");
    }
    net->sendHello();
}

void Client::choosePupitre(Pupitre p) {

}

void Client::sendNote(Note note) {
    net->sendNote(note);
}

void Client::sendReady() {
    net->sendReady();
}

void Client::loadPartition(Partition partition) {
    this->partition = partition;
    // generate global partition HERE !
}

void Client::forwardPupitreMap(std::map<Pupitre, bool>) {
    // send pupitre map to UI in order to display it HERE !
    // get choice and ack server about the pupitre choosen
}

void Client::start() {
    // start UI game screen here : load global partition etc ...
}
