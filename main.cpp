#include <QApplication>
#include <QCommandLineParser>
#include "include/engine/client.hpp"
#include "include/gui/UsernameWindow.hpp"
#include "include/network/network.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	app.setApplicationName("fanfaresimulator-client");
	app.setApplicationVersion("1.0");

	QCommandLineParser parser;
	parser.setApplicationDescription("FanfareSimulator 2k client");
	parser.addHelpOption();
	parser.addVersionOption();
	QCommandLineOption serverHostOption("server-host", "Server host", "host");
	parser.addOption(serverHostOption);
	parser.process(app);

	// username screen
	UsernameWindow usernameWindow;
	std::string username = usernameWindow.askName(); // blocks
	if (username.empty()) {
		return 1;
	}

	// client engine create
	Client engine(&app, username);

	if (parser.isSet(serverHostOption)) {
		QHostAddress serverHost = QHostAddress(parser.value(serverHostOption));
		engine.connectToServer(serverHost, PORT_NO);
	}

	return app.exec();
}
