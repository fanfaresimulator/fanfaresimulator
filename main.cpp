#include <QApplication>
#include "include/network/client.hpp"
#include "include/network/discoverer.hpp"
#include "include/UsernameWindow.hpp"
#include "include/PupitreWindow.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	Discoverer discoverer;
	NetworkClient client("Pickle Dummy");

	UsernameWindow usernameWindow;
	std::string username = usernameWindow.askName();
	usernameWindow.addName(username);
	usernameWindow.printWelcomeMessage();
	usernameWindow.printInstrumentMessage();

	PupitreWindow pupitreWindow({Pupitre(0, Instrument(2))});
	// TODO: connect(pupitreWindow->pupitreChosen)

	return app.exec();
}
