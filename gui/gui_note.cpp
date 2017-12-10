#include "../include/gui_note.hpp"

GuiNote::GuiNote(GameWindow * parent, int id, float time_begin, float time_end) : QWidget (){
    this->setParent(parent);
    this->parent = parent;
    this->visible_duration = parent->get_height() / parent->get_conversion();
    this->line_id = id;
    this->time_to_play = time_begin/*+t0*/;
    this->duration = time_end - time_begin;
    this->x = parent->get_width() * (id + 1) / (parent->get_number_of_lines() + 1);
    this->position = -1;
    this->setGeometry(x - radius_note, 0, x + radius_note, parent->get_height());
}

void GuiNote::paintEvent(QPaintEvent * event)
{
    if (this->position == -1) { return; }
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(radius_note, (int) position, radius_note, (int) (duration * parent->get_conversion()));
}

bool GuiNote::is_visible(float spent_time){
    if(spent_time>duration+time_to_play){
        return false;
    }
    if (spent_time < time_to_play - visible_duration) {
        return false;
    }
    return true;
}

void GuiNote::actualize_position(float spent_time) {
    if(spent_time>duration+time_to_play&&spent_time<time_to_play-visible_duration){
        this->position=-1;
    }
    else {
        int h = this->parent->get_height();
        float l = duration * parent->get_conversion();
        int radius = this->parent->get_musicline_radius();
        this->position = (spent_time - time_to_play) * parent->get_conversion() + h - 3 * radius - l;
    }
}

void GuiNote::print() {
    std::cout << "GuiNote{ .line_id = " << line_id <<
        "; .time_to_play = " << time_to_play <<"; .duration = " << duration <<
        " }" << std::endl;
}
