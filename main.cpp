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
	std::string username = usernameWindow.askName();

	// net create
	Discoverer discoverer;
	NetworkClient client(username);

	// client engine create
	Client clientEngine(client, username);

	// connect network server & server engine
	QObject::connect(&client, &NetworkClient::pupitresRecv, &clientEngine, &Client::forwardPupitreMap);
	QObject::connect(&client, &NetworkClient::partitionRecv, &clientEngine, &Client::loadPartition);
	QObject::connect(&client, &NetworkClient::startRecv, &clientEngine, &Client::start);

	usernameWindow.addName(username);
	usernameWindow.printWelcomeMessage();
	usernameWindow.printInstrumentMessage();

	PupitreWindow pupitreWindow({Pupitre(0, Instrument(2))});
	QObject::connect(&pupitreWindow, &PupitreWindow::pupitreChosen, &clientEngine, &Client::choosePupitre);

	std::vector<string> list;
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
	// TODO: replace with GameWindow window(700, 700, partitionGlobale);
	GameWindow window(700, 700, list);
	window.show();
	window.run(app);

	return app.exec();
}
