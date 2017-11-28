#include "music_line.hpp"
#include <QPainter>
#include <iostream>

MusicLine::MusicLine(GameWindow * parent, int id ) : QWidget (){
    this->setParent(parent);
    this->parent = parent;
    this-> id = id;
    std::cout << "constructeur " << id << std::endl;

    double x = parent->get_width()/(parent->get_number_of_lines() + 1);
    this->setGeometry((id+1)*x, 0, (id+1)*x, parent->get_height());
}

void MusicLine::setId(int number){
    this->id = id;
};

void MusicLine::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 6, Qt::SolidLine, Qt::RoundCap));
    float x = parent->get_width()  /((parent->get_number_of_lines() + 1.0)*10);

    std::cout << "id " << id << std::endl;
    painter.drawLine((id + 1) * x, 0, (id + 1) * x , parent->get_height());

}