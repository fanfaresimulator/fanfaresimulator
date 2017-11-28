#include "game_window.hpp"
#include <QPainter>

GameWindow::GameWindow() : QWidget()
{
    set_size(1000, 1000);
    set_number_of_lines(4);
    create_lines();


    /*
    setFixedSize(get_height(), get_width());

    QSlider* m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);

    QProgressBar* m_bar = new QProgressBar(this);
    m_bar->setGeometry(10, 20, 150, 20);
    m_bar->setOrientation(Qt::Horizontal);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_bar, SLOT(setValue(int))) ;
    */
}

GameWindow::GameWindow(double width, double height) : QWidget() {
    set_size(width, height);
    set_number_of_lines(4);
    create_lines();
}
void GameWindow::set_size(double width, double height) {
    this->height = height;
    this->width = width;
    setFixedSize(width, height);
}

void GameWindow::set_number_of_lines(int number) {
    this->number_of_lines = number;
}

double GameWindow::get_width() {
    return this->width;
}

double GameWindow::get_height() {
    return height;
}

int GameWindow::get_number_of_lines() {
    return number_of_lines;
}

bool GameWindow::get_is_ready() {
    return is_ready;
}

int GameWindow::get_time_start() {
    return time_start;
}

void GameWindow::create_lines(){
    int number = get_number_of_lines();
    double x = width/(number + 1);
    for (int i = 0; i < number; i++){
        lines.push_back(new MusicLine(this, i));
        std::cout << "compteur " << i << std::endl;
    }
}

void GameWindow::read_notes(char * list){
    float time1;
    float time2;
    /*
    for(int i=0;i<list.size()/3;i++){
        if((char)list(3*i+2)=='U'){
            time1=(float)list(3*i);
            int id=(int)list(3*i+1)
            for(int j=i;j<list.size()/3;j++){
                if((int)list(3*i+1)==id && (char)list(3*j+2)=='D') {
                    time2 = (float) list(3 * j);
                    break;
                }
            }
            this->note.push_back(new Note(this,id,time1,time2));
        }
    }
     */
}