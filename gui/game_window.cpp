#include "game_window.hpp"
#include <QPainter>

GameWindow::GameWindow() : QWidget()
{
    set_size(1000, 1000);
    set_number_of_lines(4);
    create_lines();


    /*
    setFixedSize(get_height(), get_width());

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);

    m_bar = new QProgressBar(this);
    m_bar->setGeometry(10, 20, 150, 20);
    m_bar->setOrientation(Qt::Horizontal);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_bar, SLOT(setValue(int))) ;

    line = new MusicLine(this);
    line->setGeometry(0,200,1000,1000);
    line->show();

    note1 = new Note(this);
    note1->setGeometry(0,200,1000,1000);
    note1->show();7

     */
}

GameWindow::GameWindow(double width, double height) : QWidget() {
    set_size(width, height);
    set_number_of_lines(4);
    create_lines();
}
void GameWindow::set_size(double width, double height) {
    this->height = height;
    this->width = width;
    setFixedSize(width, height);
}

void GameWindow::set_number_of_lines(int number) {
    this->number_of_lines = number;
}

double GameWindow::get_width() {
    return this->width;
}

double GameWindow::get_height() {
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
    double x = width/(number + 1);
    for (int i = 0; i < number; i++){
        lines.push_back(new MusicLine(this, i));
        std::cout << "compteur " << i << std::endl;
    }
}

void GameWindow::read_notes(vector<char> list){
    float time1;
    float time2;
    int id;
    while(!list.empty()) {
        time1 = (float) list[0];
        id = (int) list[1];
        for (int i = 1; i < list.size() / 3; i++) {
            if ((int) list[3 * i + 1] == id && (char) list[3 * i + 2] == 'D') {
                time2 = (float) list[3 * i];
                list.erase(list.begin()+3*i);
                list.erase(list.begin()+3*i);
                list.erase(list.begin()+3*i);
            }
            break;
        }
        this->note.push_back(new Note(this, id, time1, time2));
        list.erase(list.begin());
        list.erase(list.begin());
        list.erase(list.begin());
    }
}