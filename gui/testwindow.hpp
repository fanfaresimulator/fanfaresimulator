#ifndef DEF_TESTWINDOW
#define DEF_TESTWINDOW

#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QProgressBar>

#include "music_line.hpp"

class TestWindow : public QWidget
{
public:
    TestWindow();

private:
    QSlider *m_slider;
    QProgressBar *m_bar;
    MusicLine *line;
};

#endif