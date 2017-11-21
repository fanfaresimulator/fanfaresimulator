//#include <QApplication>
#include <QtWidgets/QApplication>
#include "gui/testwindow.hpp"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsView>
#include <qinputdialog>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	TestWindow window;

	window.show();

	bool dialogResult;
	QInputDialog *renameDialog = new QInputDialog();
	renameDialog->setTextValue("Test"); // has no effect
	QString result = renameDialog->getText(0, "Rename Label", "New name:", QLineEdit::Normal,
		"", &dialogResult);




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

