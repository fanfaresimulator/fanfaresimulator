#include "music_line.hpp"
#include <QPainter>
#include <iostream>

MusicLine::MusicLine(GameWindow * parent, int id ) : QWidget (){
    this->setParent(parent);
    this->parent = parent;
    this-> id = id;
    this->x = parent->get_width() * (id + 1) /(parent->get_number_of_lines() + 1);
    std::cout << "constructeur " << x  << std::endl;
    this->setGeometry(x, 0, x , parent->get_height());
}

void MusicLine::setId(int number){
    this->id = id;
};

void MusicLine::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 6, Qt::SolidLine, Qt::RoundCap));
    std::cout << "id " << id << std::endl;
    std::cout << "x " << x << std::endl;
    std::cout << "height " << parent->get_height() << std::endl;
    painter.drawLine(0, 0, 0 , parent->get_height());

}

double MusicLine::get_x() {
    return this->x;
}