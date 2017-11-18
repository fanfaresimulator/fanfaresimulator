#include <QApplication>
#include "gui/testwindow.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	TestWindow window;

	window.show();

	return app.exec();
}
