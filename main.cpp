#include <QApplication>
#include "gui/testwindow.hpp"
#include "include/network/client.hpp"
#include "include/network/discoverer.hpp"
#include "gui/Utilisateur.hpp" // TODO: rename to UsernameWindow
#include "include/InstrumentWindow.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// TestWindow window;

	Discoverer discoverer;
	NetworkClient client("Pickle Dummy");

	Utilisateur usernameWindow;
	std::string username = usernameWindow.askName();
	usernameWindow.addName(username);
	usernameWindow.printWelcomeMessage();
	usernameWindow.printInstrumentMessage();

	InstrumentWindow instrumentWindow;
	// TODO: connect(instrumentWindow->instrumentChosen)

	return app.exec();
}
