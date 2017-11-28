#include "game_window.hpp"
#include <QPainter>

GameWindow::GameWindow() : QWidget()
{
    set_size(1000, 1000);

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
}
void GameWindow::set_size(int width, int height) {
    this->height = height;
    this->width = width;
    setFixedSize(width, height);
}

int GameWindow::get_width() {
    return width;
}

int GameWindow::get_height() {
    return height;
}

bool GameWindow::get_is_ready() {
    return is_ready;
}

int GameWindow::get_time_start() {
    return time_start;
}