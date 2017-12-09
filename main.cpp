#include <QApplication>
#include "include/network/client.hpp"
#include "include/client.hpp"
#include "include/network/discoverer.hpp"
#include "include/UsernameWindow.hpp"
#include "include/PupitreWindow.hpp"
#include "gui/game_window.hpp"

void *operator new(size_t size) {
	return nullptr;
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	// username screen
	UsernameWindow usernameWindow;
	std::string username = usernameWindow.askName(); // blocks
	if (username.empty()) {
		return 1;
	}

	// client engine create
	Client engine(&app, username);

	return app.exec();
}
