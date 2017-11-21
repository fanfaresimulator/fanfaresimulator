#include "include/network_server.hpp"
#include <QApplication>


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	NetworkServer serv;
	return app.exec();
}
