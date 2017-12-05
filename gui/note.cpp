#include "note.hpp"

GuiNote::GuiNote(GameWindow * parent, int id, float time_begin, float time_end) : QWidget (){
    this->setParent(parent);
    this->parent=parent;
    this->line_id=id;
    this->time_to_play=time_begin/*+t0*/;
    this->duration=time_end-time_begin;
    this->x = parent->get_width() * (id + 1) /(parent->get_number_of_lines() + 1);
    this->position=-1;
    this->visible_duration=parent->get_height()-3*parent->get_musicline_radius();
    this->setGeometry(x-radius_note, 0, x+radius_note , parent->get_height());
}

void GuiNote::paintEvent(QPaintEvent * event)//position calculé par fonction main
{
    if(this->position==-1){return;}
    //this->setGeometry(x, 0, x , this->parent->get_height());
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(radius_note,position,radius_note,duration*10);
}

bool GuiNote::is_visible(float spent_time){
    if(spent_time>duration+time_to_play){
        return false;
    }
    if(spent_time<time_to_play-visible_duration){
        return false;
    }
    return true;
}

void GuiNote::actualize_position(int spent_time){
    if(spent_time>duration+time_to_play&&spent_time<time_to_play-visible_duration){
        this->position=-1;
    }
    else {
        this->position = 500-(time_to_play - spent_time);
    }
}
