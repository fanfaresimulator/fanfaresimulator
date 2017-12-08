#ifndef FANFARESIMULATOR_MUSIC_LINE_H
#define FANFARESIMULATOR_MUSIC_LINE_H

#include <iostream>
#include <QWidget>
#include "game_window.hpp"

using namespace std;

class GameWindow;

class MusicLine : public QWidget{

public:

    MusicLine(GameWindow * parent, int id );

    void setId(int id);

    int get_x();

    void set_is_pushed(bool state);

    int get_radius();

protected:
    void paintEvent(QPaintEvent *event) final;

private:
    int id;
    string color;

    int x;

    int radius;

    bool isPushed;

    GameWindow* parent;

};


#endif //FANFARESIMULATOR_MUSIC_LINE_H
