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
class GameWindow : public QWidget
{
public:
    GameWindow();
    GameWindow(int width, int height);

    void set_size(int width, int height);

    void set_number_of_lines(int number);


    int get_height();
    int get_width();
    int get_number_of_lines();

    bool get_is_ready();

    int get_time_start();

    void create_lines();

private:
    int height;
    int width;
    bool is_ready;
    int time_start;
    int number_of_lines;
    MusicLine** lines;
    vector<Note*> note;
};

#endif