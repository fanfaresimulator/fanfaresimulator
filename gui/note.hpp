//
// Created by Sophie Degabriel on 21/11/2017.
//

#ifndef FANFARESIMULATOR_NOTE_HPP
#define FANFARESIMULATOR_NOTE_HPP


#include <iostream>
#include <QWidget>
#include <QPainter>
#include "game_window.hpp"

class GameWindow;

class GuiNote : public QWidget {

public:
    float visible_duration=500;
    GameWindow* parent;
    int line_id;
    float duration;
    float time_to_play;
    int radius_note=10;
    int position;
    float x;

    GuiNote(GameWindow * parent, int id, float time_begin, float time_end);

    bool is_visible(float spent_time);
    void actualize_position(int spent_time);

protected:
    void paintEvent(QPaintEvent *event);

};


#endif //FANFARESIMULATOR_NOTE_HPP
