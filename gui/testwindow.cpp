#include "testwindow.hpp"
#include <QPainter>

TestWindow::TestWindow() : QWidget()
{
    setFixedSize(1000, 1000);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);

    m_bar = new QProgressBar(this);
    m_bar->setGeometry(10, 20, 150, 20);
    m_bar->setOrientation(Qt::Horizontal);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_bar, SLOT(setValue(int))) ;

    line = new MusicLine(this);

    line->show();

}
