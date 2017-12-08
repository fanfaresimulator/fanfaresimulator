#include <QApplication>
#include "include/network/client.hpp"
#include "include/network/discoverer.hpp"
#include "include/UsernameWindow.hpp"
#include "include/PupitreWindow.hpp"
#include "gui/game_window.hpp"

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
    window.run(app);
    return 0;

    // UsernameWindow usernameWindow;
    // std::string username = usernameWindow.askName();
    // usernameWindow.addName(username);
    // usernameWindow.printWelcomeMessage();
    // usernameWindow.printInstrumentMessage();
    //
    // PupitreWindow pupitreWindow({Pupitre(0, Instrument(2))});
    // // TODO: connect(pupitreWindow->pupitreChosen)
    //
    // return app.exec();
}
