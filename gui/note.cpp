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

Note::Note(QWidget * parent) : QWidget (){
    this->setParent(parent);
    this->line_id=1;
    this->time_to_play=-1;
    this->duration=0.3;
    this->is_long=true;
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

/*while(!list.isEmpty()){
 * float temps1=(float)list.pop();
 * int id=(int)list.pop();
 * list.pop();
 * for(int i=0;i<list.size()/3;i++){
 * if ((int)list(3*i+1)==id){
 * float temps2=(float) list(3*i);
 * list.delete(3*i);
 * list.delete(3*i);
 * list.delete(3*i);
 * break;
 * }
 * }
 * this->note.add(new Note(this,id,temps1,temps2));
 * }
 *
 * for(int i=0;i<list.size()/3;i++){
 * if((char)list(3*i+2)=='U'){
 * float temps1=(float)list(3*i);
 * int id=(int)list(3*i+1)
 * for(int j=i;j<list.size()/3;j++){
 * if((int)list(3*i+1)==id && (char)list(3*j+2)=='D'){
 * float temps2=(float)list(3*j);
 * break;
 * }
 * }
 * this->note.add(new Note(this,id,temps1,temps2));
 * }
 * }
 * */
