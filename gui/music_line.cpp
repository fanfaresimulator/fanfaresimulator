#include "music_line.hpp"
#include <QPainter>

MusicLine::MusicLine(QWidget * parent ) : QWidget (){
    this->setParent(parent);
}

void MusicLine::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(100, 100, 900, 100);
}