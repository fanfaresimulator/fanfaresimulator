#include <QApplication>
#include <QTime>
#include "include/network/client.hpp"
#include "include/InstrumentWindow.hpp"
#include "gui/game_window.hpp"

typedef basic_string<char> string;


int main(int argc, char *argv[]) {
    vector<string> list;
    QTime t0 = QTime::currentTime();
    cout << t0.msec() << endl;
    t0.start();
    list.push_back("1000");
    list.push_back("0");
    list.push_back("U");
    list.push_back("1500");
    list.push_back("0");
    list.push_back("D");
    list.push_back("3000");
    list.push_back("1");
    list.push_back("U");
    list.push_back("5000");
    list.push_back("1");
    list.push_back("D");
    QApplication app(argc, argv);
    GameWindow window(1000, 1000, list);
    window.show();
    cout << t0.elapsed() << endl;
    while (true) {
        int spent_time = t0.elapsed();
        /*if (abs(spent_time-1000) < 2){
            cout<<"main  " <<spent_time<<endl;
        }*/
        window.actualize_notes(spent_time);
        window.update();
        QCoreApplication::processEvents();
    }
    return app.exec();
}
