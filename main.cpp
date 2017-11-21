//#include <QApplication>
#include <QtWidgets/QApplication>
#include "gui/game_window.hpp"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsView>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	GameWindow window;

	window.set_size(1500, 1000);

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
