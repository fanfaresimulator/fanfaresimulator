#include <QApplication>
#include "include/network/client.hpp"
#include "include/client.hpp"
#include "include/network/discoverer.hpp"
#include "include/UsernameWindow.hpp"
#include "include/PupitreWindow.hpp"
#include "gui/game_window.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	// username screen
	UsernameWindow usernameWindow;
	std::string username = usernameWindow.askName(); // blocks

	// client engine create
	Client engine(&app, username);

	return app.exec();
}
