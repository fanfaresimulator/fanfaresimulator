#include <QApplication>
#include "include/network/client.hpp"
#include "include/client.hpp"
#include "include/network/discoverer.hpp"
#include "include/UsernameWindow.hpp"
#include "include/PupitreWindow.hpp"

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

	//* CONNECTS network server & server engine */

	QObject::connect(&client, &NetworkClient::pupitresRecv,
					 &clientEngine, &Client::forwardPupitreMap);
	QObject::connect(&client, &NetworkClient::partitionRecv,
					 &clientEngine, &Client::loadPartition);
	QObject::connect(&client, &NetworkClient::startRecv,
					 &clientEngine, &Client::start);


	return app.exec();
}
