//#include <QApplication>
#include <QtWidgets/QApplication>
#include "gui/testwindow.hpp"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsView>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	TestWindow window;

	window.show();



	return app.exec();
}

/*int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyScene scene;
    scene.setSceneRect(-150, -150, 300, 300);

    QGraphicsView view(&scene);
    view.setWindowTitle("Ma première scène");
    view.show();
    return app.exec();
}*/
