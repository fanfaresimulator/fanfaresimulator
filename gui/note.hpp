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
    int line_id;
    float duration;
    bool is_long;
    float time_to_play;
    int radius_note=10;

    Note(QWidget * parent, int id, float time_begin, float time_end);

protected:
    void paintEvent(QPaintEvent *event, int position);

};


#endif //FANFARESIMULATOR_NOTE_HPP
