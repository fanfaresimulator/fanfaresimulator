#ifndef DEF_TESTWINDOW
#define DEF_TESTWINDOW
#include <vector>
#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QProgressBar>
#include <QPainter>

#include "music_line.hpp"
#include "note.hpp"
using namespace std;

class GameWindow : public QWidget {
public:
    GameWindow();
    GameWindow(int width, int height);

    void set_size(int width, int height);


    int get_height();
    int get_width();

    bool get_is_ready();

    int get_time_start();

    void read_notes(char * list);

private:
    int height;
    int width;
    bool is_ready;
    int time_start;
    MusicLine *lines[];
    vector<Note*>  note;
};

#endif