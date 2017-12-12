#include "../include/engine/state.hpp"

State::State(std::vector<Note> notes, std::vector<NoteGlobale> gNotes) {
    listOfNotes = notes;
    listOfGNotes = gNotes;

    // reverse vecs in order to use pop back method
    std::reverse(listOfNotes.begin(),listOfNotes.end());
    std::reverse(listOfGNotes.begin(),listOfGNotes.end());


}

void State::startChrono() {
    t0.start();
}

double State::getCurrentTime() {
    return (double)t0.elapsed()/1000;
}

