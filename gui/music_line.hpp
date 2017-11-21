//
// Created by antoine on 21/11/17.
//

#ifndef FANFARESIMULATOR_MUSIC_LINE_H
#define FANFARESIMULATOR_MUSIC_LINE_H

#include <iostream>
#include <QWidget>

typedef std::string string;


class MusicLine : public QWidget{

public:
    int id;
    string color;
    int key;

    MusicLine(QWidget * parent );

protected:
    void paintEvent(QPaintEvent *event);

};


#endif //FANFARESIMULATOR_MUSIC_LINE_H
