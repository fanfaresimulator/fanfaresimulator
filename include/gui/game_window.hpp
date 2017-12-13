#pragma once

#include <vector>
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QKeyEvent>

#include "gui/music_line.hpp"
#include "gui/gui_note.hpp"
#include "synth/partitionglobale.hpp"

using namespace std;

class GuiNote;
class MusicLine;

class GameWindow : public QWidget {
    Q_OBJECT
public:
    GameWindow();
    GameWindow(int width, int height);
    GameWindow(int width, int height, vector<string> list);
    GameWindow(int width, int height, PartitionGlobale partition);
    GameWindow(int width, int height, PartitionGlobale partition, int number_of_lines);

    int get_height();
    int get_width();
    int get_number_of_lines();
    int get_musicline_radius();
    float get_conversion();
    void set_size(int width, int height);
    void set_speed(float speed);
    void run(QApplication *app);

    void keyPressEvent(QKeyEvent *touche);
    void keyReleaseEvent(QKeyEvent *touche);

signals:
    void keyChanged(int key, double t, bool pressed);

private:
    int width, height;
    int number_of_lines = 4;
    float speed = 1.0;
    vector<MusicLine*> lines;
    vector<GuiNote*> note;
    bool running = false;
    QTime t0;
    vector<Qt::Key> keys = {Qt::Key_D, Qt::Key_F, Qt::Key_J, Qt::Key_K};

    void add_note(GuiNote* n);
    void create_lines();
    void read_notes(vector<string> list);
    void actualize_notes(float spent_time);
    int getPositionNote(int index);
    int getDurationNote(int index);
    int getKeyIndex(Qt::Key key);
    void printKeys();
};
