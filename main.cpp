#include <QApplication>
#include "include/client.hpp"
#include "include/UsernameWindow.hpp"

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
