#include <QtWidgets/QApplication>
#include "gui/game_window.hpp"

typedef basic_string<char> string;


int main(int argc, char *argv[]) {
    vector<string> list;
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
    int time_start=clock();
    int spent_time=0;
    while(spent_time<7000){
        spent_time=(float)(clock()-time_start)*1000/CLOCKS_PER_SEC;
        window.actualize_notes(spent_time);
        //cout<<window.getPositionNote(0)<<endl;
        window.update();
        QCoreApplication::processEvents();
    }
    //window.show();
    return app.exec();
    //return 0;
}
