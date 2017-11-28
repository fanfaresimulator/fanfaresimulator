#include "music_line.hpp"

MusicLine::MusicLine(GameWindow * parent, int id ) : QWidget (){
    this->setParent(parent);
    this->parent = parent;
    this-> id = id;
    this->x = parent->get_width() * (id + 1) /(parent->get_number_of_lines() + 1);
    this->setGeometry(x, 0, x, parent->get_height());
}

void MusicLine::setId(int number){
    this->id = number;
};

void MusicLine::paintEvent(QPaintEvent *event)
{
    this->setGeometry(x, 0, x, parent->get_height());
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 10, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(0, 0, 0 , parent->get_height());

}

int MusicLine::get_x() {
    return this->x;
}