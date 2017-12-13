#include "../include/gui/game_window.hpp"

GameWindow::GameWindow() : GameWindow(700, 700) {}

GameWindow::GameWindow(int width, int height, PartitionGlobale partition) :
        GameWindow(width, height, partition, 4) {}

GameWindow::GameWindow(int width, int height, PartitionGlobale partition,
        int number_of_lines) : QWidget(), number_of_lines(number_of_lines) {
    set_size(width, height);
    create_lines();

    std::vector<NoteGlobale> notes = partition.getNotes();
    int size = notes.size();
    for (int i=0;i<size;i++) {
        if (!notes[i].getSignal()) {
            continue;
        }

        double time1 = notes[i].getTime();
        int key = notes[i].getKey();
        for (int j = i; j < size; j++) {
            if (notes[j].getKey() == key && !notes[j].getSignal()) {
                double time2 = notes[j].getTime();
                this->add_note(new GuiNote(this, key, time1*1000, time2*1000));
                break;
            }
        }
    }

    std::cout << "Number of GUI notes: " << note.size() << std::endl;
    // for (int i = 0; i < note.size(); ++i) {
    //     note[i]->print();
    // }
}

GameWindow::GameWindow(int width, int height) : QWidget() {
    set_size(width, height);
    create_lines();
}

GameWindow::GameWindow(int width, int height, vector<string> list) : QWidget() {
    set_size(width, height);
    create_lines();
    read_notes(list);
}

void GameWindow::set_size(int width, int height) {
    this->height = height;
    this->width = width;
    setFixedSize(width, height);
}

int GameWindow::get_height() {
    return height;
}

int GameWindow::get_width() {
    return width;
}

int GameWindow::get_number_of_lines() {
    return number_of_lines;
}

void GameWindow::add_note(GuiNote* n) {
    this->note.push_back(n);
}

void GameWindow::create_lines() {
    int number = get_number_of_lines();
    for (int i = 0; i < number; i++){
        lines.push_back(new MusicLine(this, i));
    }
}

void GameWindow::actualize_notes(float spent_time) {
    for(GuiNote* n:this->note){
        n->actualize_position(spent_time);
    }
}

void GameWindow::read_notes(vector<string> list) {
    float time1;
    float time2;
    int id;
    while(!list.empty()) {
        time1 = std::stod(list[0]);
        id = (int) std::stod(list[1]);
        for (size_t i = 1; i < list.size() / 3; i++) {
            if ((int) std::stod(list[3 * i + 1]) == id && list[3 * i + 2].compare("D") == 0) {
                time2 = std::stod(list[3 * i]);
                list.erase(list.begin()+3*i);
                list.erase(list.begin()+3*i);
                list.erase(list.begin()+3*i);
            }
            break;
        }
        this->note.push_back(new GuiNote(this, id, time1, time2));
        list.erase(list.begin());
        list.erase(list.begin());
        list.erase(list.begin());
    }
}

int GameWindow::getPositionNote(int index) {
    int p = this->note[index]->position;
    return p;
}

int GameWindow::getDurationNote(int index) {
    int p = this->note[index]->duration;
    return p;
}

void GameWindow::set_speed(float speed) {
    this->speed = speed;
}

float GameWindow::get_conversion() {
    return (float)height / 4000 * speed;
}

int GameWindow::get_musicline_radius() {
    return this->lines[0]->get_radius();
}

void GameWindow::printKeys() {
    std::cout << "Keybindings:";
    for (size_t i = 0; i < keys.size(); ++i) {
        std::cout << " " << QKeySequence(keys[i]).toString().toStdString();
    }
    std::cout << std::endl;
}

void GameWindow::run(QApplication *app) {
    if (running) {
        return;
    }

    printKeys();

    this->show();
    running = true;
    t0.start();
    while (true) {
        int spent_time = t0.elapsed();
        this->actualize_notes(spent_time);
        this->update();

        app->processEvents();
    }
}

// partie clavier

int GameWindow::getKeyIndex(Qt::Key key) {
    for (size_t i = 0; i < keys.size(); ++i) {
        if (key == keys[i]) {
            return i;
        }
    }
    return -1;
}

void GameWindow::keyPressEvent(QKeyEvent *event) {
    if (!running || event->isAutoRepeat()) {
        return;
    }
    emit keyChanged(getKeyIndex(Qt::Key(event->key())), (double)t0.elapsed()/1000, true);
}
void GameWindow::keyReleaseEvent(QKeyEvent *event) {
    if (!running || event->isAutoRepeat()) {
        return;
    }
    emit keyChanged(getKeyIndex(Qt::Key(event->key())), (double)t0.elapsed()/1000, false);
}
