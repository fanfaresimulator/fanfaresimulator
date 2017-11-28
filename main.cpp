#include <QtWidgets/QApplication>
#include "gui/game_window.hpp"

typedef basic_string<char> string;


int main(int argc, char *argv[]) {
    vector<string> list;
    list.push_back("1000");
    list.push_back("0");
    list.push_back("U");
    list.push_back("5000");
    list.push_back("0");
    list.push_back("D");
    list.push_back("2000");
    list.push_back("1");
    list.push_back("U");
    list.push_back("5000");
    list.push_back("1");
    list.push_back("D");
    QApplication app(argc, argv);
    GameWindow window(1000, 1000, list);
    window.show();
    return app.exec();
}
