#include <QApplication>
#include "gui/testwindow.hpp"
#include "include/network_client.hpp"
#include "gui/Utilisateur.hpp" // TODO: rename to UsernameWindow
#include "include/InstrumentWindow.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	NetworkClient client("Pickle Dummy");

	Utilisateur usernameWindow;
	std::string username = usernameWindow.askName();
	usernameWindow.addName(username);
	usernameWindow.printWelcomeMessage();
	usernameWindow.printInstrumentMessage();

	InstrumentWindow win({ "piano","violon","violoncelle","triangle" });
	// TODO: connect(instrumentWindow->instrumentChosen)

	return app.exec();
}
