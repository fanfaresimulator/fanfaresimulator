//
// Created by Sophie Degabriel on 21/11/2017.
//

#ifndef FANFARESIMULATOR_NOTE_HPP
#define FANFARESIMULATOR_NOTE_HPP


#include <iostream>
#include <QWidget>
#include <QPainter>

class Note : public QWidget {

public:
    float visible_duration=0.3;
    int line_id;
    float duration;
    bool is_long;
    float time_to_play;
    int radius_note=10;
    int position;

    Note(QWidget * parent, int id, float time_begin, float time_end);

    bool is_visible(float spent_time);
    void actualize_position(float spent_time);

protected:
    void paintEvent(QPaintEvent *event);

};


#endif //FANFARESIMULATOR_NOTE_HPP
