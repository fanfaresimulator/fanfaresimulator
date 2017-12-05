#include <QApplication>
#include "include/network/client.hpp"
#include "include/network/discoverer.hpp"
#include "include/UsernameWindow.hpp"
#include "include/InstrumentWindow.hpp"
#include "gui/game_window.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

  // TODO: add this back
	/*Discoverer discoverer;
	NetworkClient client("Pickle Dummy");

	UsernameWindow usernameWindow;
	std::string username = usernameWindow.askName();
	usernameWindow.addName(username);
	usernameWindow.printWelcomeMessage();
	usernameWindow.printInstrumentMessage();

	InstrumentWindow instrumentWindow;
	// TODO: connect(instrumentWindow->instrumentChosen)
  */

  vector<string> list;
  list.push_back("2000");
  list.push_back("0");
  list.push_back("U");
  list.push_back("2050");
  list.push_back("0");
  list.push_back("D");
  list.push_back("3000");
  list.push_back("1");
  list.push_back("U");
  list.push_back("3100");
  list.push_back("1");
  list.push_back("D");
  GameWindow window(500, 500, list);
  window.show();
  int time_start=clock();
  int spent_time=0;
  while(spent_time<7000){
      spent_time=(float)(clock()-time_start)*1000/CLOCKS_PER_SEC;
      window.actualize_notes(spent_time);
      //cout<<window.getPositionNote(0)<<endl;
      window.update();
      //cout<<window.getPositionNote(1)<<" "<<(float)(clock()*1000/CLOCKS_PER_SEC)<<endl;
      QCoreApplication::processEvents();
  }

	return app.exec();
}
