#include <QApplication>
#include "include/network/client.hpp"
#include "include/network/discoverer.hpp"
#include "include/UsernameWindow.hpp"
#include "include/InstrumentWindow.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	Discoverer discoverer;
	NetworkClient client("Pickle Dummy");

	UsernameWindow usernameWindow;
	std::string username = usernameWindow.askName();
	usernameWindow.addName(username);
	usernameWindow.printWelcomeMessage();
	usernameWindow.printInstrumentMessage();

	InstrumentWindow instrumentWindow;
	// TODO: connect(instrumentWindow->instrumentChosen)

	return app.exec();
}
