//
// Created by Sophie Degabriel on 21/11/2017.
//

#include "note.hpp"

Note::Note(QWidget * parent, int id, float time_begin, float time_end) : QWidget (){
    this->setParent(parent);
    this->line_id=id;
    this->time_to_play=time_begin/*+t0*/;
    this->duration=time_end-time_begin;
    if(duration>0.2){
        this->is_long=true;
    }
}

void Note::paintEvent(QPaintEvent * event, int position)//position calculé par fonction main
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(QPointF(line_id/* *col_width*/,position),radius_note,radius_note);
    if(is_long){
        painter.drawRect(line_id/* *col_width*/-radius_note,position-radius_note,radius_note*2,duration);
    }
}