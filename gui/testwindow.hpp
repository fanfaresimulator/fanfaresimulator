#ifndef DEF_TESTWINDOW
#define DEF_TESTWINDOW

#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QProgressBar>
#include <QPainter>

#include "music_line.hpp"
#include "note.hpp"

class TestWindow : public QWidget
{
public:
    TestWindow();

private:
    QSlider *m_slider;
    QProgressBar *m_bar;
    MusicLine *line;
    Note *note1;
};

#endif