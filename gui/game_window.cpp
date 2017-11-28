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

GameWindow::GameWindow(int width, int height) : QWidget() {
    set_size(width, height);
    set_number_of_lines(4);
    create_lines();
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
    return width;
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
    int x = this->width/(number+1);
    MusicLine* test = new MusicLine(this);
    test->setGeometry(0,200,1000,1000);
    test->show();
    for (int i = 0; i < number; i++){
        lines[i] = new MusicLine(this);
        lines[i]->setGeometry((i+1)*x,0,(i+1)*x,get_height());
        lines[i]->show();
    }
}
