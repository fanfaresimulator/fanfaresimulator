#include "music_line.hpp"
#include <QPainter>
#include <iostream>

MusicLine::MusicLine(GameWindow * parent ) : QWidget (){
    this->setParent(parent);
    this->parent = parent;
}

void MusicLine::setId(int number){
    this->id = id;
};

void MusicLine::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
    double x = parent->get_width()/(parent->get_number_of_lines() + 1);
    painter.drawLine((id+1)*x, 0, (id+1)*x, parent->get_height());
}