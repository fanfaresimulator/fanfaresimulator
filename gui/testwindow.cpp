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
    line->setGeometry(0,200,1000,1000);
   line->show();

    note1 = new Note(this);
    line->setGeometry(0,200,1000,1000);
    note1->show();



}


void TestWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
// painter.drawEllipse(500, 500, 40, 40);
}
