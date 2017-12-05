#include "music_line.hpp"

MusicLine::MusicLine(GameWindow * parent, int id ) : QWidget (){
    this->setParent(parent);
    this->parent = parent;
    this-> id = id;
    this->x = parent->get_width() * (id + 1) /(parent->get_number_of_lines() + 1);
    this->setGeometry(x, 0, x, parent->get_height());
    this->radius = 50;
    this->isPushed = false;
}

void MusicLine::setId(int number){
    this->id = number;
};

void MusicLine::paintEvent(QPaintEvent *event)
{
    int h = parent->get_height();
    this->setGeometry(x - radius, 0, x - radius, h);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 10, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(radius, 0, radius, h);
    if (isPushed) {
        painter.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    }
    painter.drawEllipse(radius / 2, h - 2 * radius, radius, radius);
    painter.setPen(QPen(Qt::black, 10, Qt::SolidLine, Qt::RoundCap));
}

int MusicLine::get_x() {
    return this->x;
}

