#include "note.hpp"

Note::Note(QWidget * parent, int id, float time_begin, float time_end) : QWidget (){
    this->setParent(parent);
    this->line_id=id;
    this->time_to_play=time_begin/*+t0*/;
    this->duration=time_end-time_begin;
    if(duration>0.2){
        this->is_long=true;
    }
    this->position=-1;
}

void Note::paintEvent(QPaintEvent * event)//position calculé par fonction main
{
    if(this->position==-1){return;}
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(QPointF(line_id/* *col_width*/,position),radius_note,radius_note);
    if(is_long){
        painter.drawRect(line_id/* *col_width*/-radius_note,position-radius_note,radius_note*2,duration);
    }
}

bool Note::is_visible(float spent_time){
    if(spent_time>duration+time_to_play){
        return false;
    }
    if(spent_time<time_to_play-visible_duration){
        return false;
    }
    return true;
}

void Note::actualize_position(float spent_time){
    if(!is_visible(spent_time)){
        this->position=-1;
    }
    else {
        this->position = (time_to_play - spent_time) * 100;
    }
}