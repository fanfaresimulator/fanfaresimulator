//
// Created by Sophie Degabriel on 21/11/2017.
//

#include "note.hpp"

Note::Note(QWidget * parent ) : QWidget (){
    this->setParent(parent);
    setFixedSize(1000, 1000);

}

void Note::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(500, 500, 40, 40);;
}