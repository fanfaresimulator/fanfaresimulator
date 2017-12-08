#include "../include/ui.hpp"

UI::UI(PartitionGlobale partition) {
  window = new GameWindow();
}

void UI::Draw() {
    int size=partition.size();
    double time1,time2;
    for (int i=0;i<size;i++) {
        if (partion[i].signal) {
            time1 = partition[i].get_timestamp();
            int key = partition[i].get_key();
            for (int j = i; j < size; j++) {
                if (partition[j].get_key() == key&&partition[j].signal) {
                    time2 = partition[j].get_timestamp();
                    window.add_note(new GuiNote(window, key, time1, time2));
                    break;
                }
            }
        }
    }
}

void UI::startStream() {
    QApplication app(argc, argv);
    QTime t0 = QTime::currentTime();
    this->window.show();
    t0.start();
    while (true) {
        int spent_time = t0.elapsed();
        this->window.actualize_notes(spent_time);
        this->window.update();
        QCoreApplication::processEvents();
    }
}
