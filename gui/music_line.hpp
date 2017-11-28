#ifndef FANFARESIMULATOR_MUSIC_LINE_H
#define FANFARESIMULATOR_MUSIC_LINE_H

#include <iostream>
#include <QWidget>
#include "game_window.hpp"
typedef std::string string;
class GameWindow;

class MusicLine : public QWidget{

public:

    MusicLine(GameWindow * parent, int id );

    void setId(int id);

    int get_x();

protected:
    void paintEvent(QPaintEvent *event) final;

private:
    int id;
    string color;
    int key;

    int x;

    GameWindow* parent;

};


#endif //FANFARESIMULATOR_MUSIC_LINE_H
