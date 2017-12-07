#ifndef DEF_TESTWINDOW
#define DEF_TESTWINDOW
#include <vector>
#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QProgressBar>
#include <QPainter>
#include <QTime>

#include "music_line.hpp"
#include "gui_note.hpp"

using namespace std;

class GuiNote;
class MusicLine;

class GameWindow : public QWidget
{
  Q_OBJECT
public:
    GameWindow(int width, int height, vector<string>, QTime t0);
    GameWindow();
    GameWindow(int width, int height);
    GameWindow(int width, int height, vector<string> list);

    void set_size(int width, int height);

    void set_number_of_lines(int number);
    void add_note(GuiNote* n){
        this->note.push_back(n);
    }

    int get_height();

    int get_width();
    int get_number_of_lines();

    bool get_is_ready();

    int get_time_start();

    void create_lines();

    void read_notes(vector<string> list);
    void actualize_notes(float spent_time);
    int getPositionNote(int index);
    int getDurationNote(int index);
    int get_musicline_radius();

    void keyPressEvent(QKeyEvent *touche);
    void keyReleaseEvent(QKeyEvent *touche);
    float get_conversion();

private:
    int height;
    int width;
    bool is_ready;
    int time_start;
    int number_of_lines;
    vector<MusicLine*> lines;
    vector<GuiNote*> note;
    float conversion;
    QTime t0;

signals:
    void getreleasednote(int,int);
    void getpressednote(int,int);
};

#endif
