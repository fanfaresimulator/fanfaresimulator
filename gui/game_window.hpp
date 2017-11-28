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

class MusicLine;
using namespace std;
class GameWindow : public QWidget
{
public:
    GameWindow();
    GameWindow(double width, double height);

    void set_size(double width, double height);

    void set_number_of_lines(int number);


    double get_height();
    double get_width();
    int get_number_of_lines();

    bool get_is_ready();

    int get_time_start();

    void create_lines();

    void read_notes(char * list);

private:
    double height;
    double width;
    bool is_ready;
    int time_start;
    int number_of_lines;
    vector<MusicLine*> lines;
    vector<Note*> note;
};

#endif