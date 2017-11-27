#pragma once

#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QProgressBar>

class TestWindow : public QWidget
{
public:
    TestWindow();

private:
    QSlider *m_slider;
    QProgressBar *m_bar;
};
