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

	// net create
	Discoverer discoverer;
	NetworkClient net(username);

	// client engine create
	Client engine(&app, &net, username);

	// connect network server & server engine
	QObject::connect(&net, &NetworkClient::pupitresRecv, &engine, &Client::forwardPupitreMap);
	QObject::connect(&net, &NetworkClient::partitionRecv, &engine, &Client::loadPartition);
	QObject::connect(&net, &NetworkClient::startRecv, &engine, &Client::start);

	return app.exec();
}
