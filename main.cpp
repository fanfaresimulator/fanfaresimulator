#include <QApplication>
#include "gui/testwindow.hpp"
#include "include/network/client.hpp"
#include "include/network/discoverer.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	TestWindow window;

	Discoverer discoverer;
	NetworkClient client("Pickle Dummy");

	window.show();

	return app.exec();
}
