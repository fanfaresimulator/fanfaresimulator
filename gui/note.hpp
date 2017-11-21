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
    int color;
    int line;
    int position;
    int distance;//identifiant

    Note(QWidget * parent );

protected:
    void paintEvent(QPaintEvent *event);

};


#endif //FANFARESIMULATOR_NOTE_HPP
