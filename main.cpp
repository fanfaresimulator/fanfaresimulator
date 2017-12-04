#include <QApplication>
#include "gui/testwindow.hpp"
#include "include/network/client.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	TestWindow window;

	NetworkClient client("Pickle Dummy");

	window.show();

	return app.exec();
}
