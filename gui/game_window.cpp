#include <QKeyEvent>
#include "game_window.hpp"


GameWindow::GameWindow() : QWidget()
{
    set_size(1000, 1000);
    set_number_of_lines(4);
    create_lines();
}

GameWindow::GameWindow(int width, int height) : QWidget() {
    set_size(width, height);
    set_number_of_lines(4);
    create_lines();
}

GameWindow::GameWindow(int width, int height, vector<string> list) : QWidget() {
    set_size(width, height);
    set_number_of_lines(4);
    this->conversion = height * 1.0 / 4000;
    create_lines();
    read_notes(list);
    /*for(GuiNote* n:note){
        n->position=100;
    }*/
    //std::cout << this->note.size() << std::endl;
}

void GameWindow::set_size(int width, int height) {
    this->height = height;
    this->width = width;
    setFixedSize(width, height);
}

void GameWindow::set_number_of_lines(int number) {
    this->number_of_lines = number;
}

int GameWindow::get_width() {
    return this->width;
}

int GameWindow::get_height() {
    return height;
}

int GameWindow::get_number_of_lines() {
    return number_of_lines;
}

bool GameWindow::get_is_ready() {
    return is_ready;
}

int GameWindow::get_time_start() {
    return time_start;
}

void GameWindow::create_lines(){
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
        for (int i = 1; i < list.size() / 3; i++) {
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

int GameWindow::getPositionNote(int index){
    int p = this->note[index]->position;
    return p;
}

int GameWindow::getDurationNote(int index){
    int p = this->note[index]->duration;
    return p;
}

float GameWindow::get_conversion() {
    return this->conversion;
}

int GameWindow::get_musicline_radius(){
    return this->lines[0]->get_radius();
}

void GameWindow::keyPressEvent(QKeyEvent *touche) {
    if(touche->key() == Qt::Key_A){
        emit getpressednote(1,0);
    }
    if(touche->key() == Qt::Key_R){
        emit getpressednote(2,0);
    }
    if(touche->key() == Qt::Key_U){
        emit getpressednote(3,0);
    }
    if(touche->key() == Qt::Key_P){
        emit getpressednote(4,0);
    }
    else{
        emit getpressednote(0,0);
    }
}
void GameWindow::keyReleaseEvent(QKeyEvent *touche) {
    if(touche->key() == Qt::Key_A){
        emit getreleasednote(1,0);
    }
    if(touche->key() == Qt::Key_R){
        emit getreleasednote(2,0);
    }
    if(touche->key() == Qt::Key_U){
        emit getreleasednote(3,0);
    }
    if(touche->key() == Qt::Key_P){
        emit getreleasednote(4,0);
    }
    else{
        emit getreleasednote(0,0);
    }
}