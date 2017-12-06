#include "../include/state.hpp"

double State::getBlockTime() const {
    return blockTime;
}

int State::getKey() const {
    return key;
}

double State::getTimeLastEvent() const {
    return timeLastEvent;
}

void State::setBlockTime(double newBlockTime) {
    if(newBlockTime < blockTime) {
        throw std::invalid_argument("invalid block time");
    }
    blockTime = newBlockTime;
}

void State::setKey(int newKey) {
    if(newKey < 0 || newKey > 4){
        throw std::invalid_argument("invalid key");
    }
    key = newKey;
}

void State::setTimeLastEvent(double newTimeLastEvent) {
    if(timeLastEvent > newTimeLastEvent) {
        throw std::invalid_argument("wrong time last event");
    }
    timeLastEvent = newTimeLastEvent;
}

double State::getCurrentTime() {
    return 1.0;
}

void State::reinitialize() {
    setKey(0);
    stateChanged = false;
}

bool State::checkStateWithNote(int globalNoteKey, bool globalNoteSignal,
                               double gloablNoteTimeStamp) {
    double USER_TOLL = 1.0;
    bool keyEquals = (getKey() == globalNoteKey);
    bool signalEquals = (signal == globalNoteSignal);
    bool timesEquals = (getTimeLastEvent() >= gloablNoteTimeStamp - USER_TOLL) &&
            (getTimeLastEvent() <= gloablNoteTimeStamp + USER_TOLL);

    return keyEquals && signalEquals && timesEquals;

}