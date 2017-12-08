#pragma once

#include <string>
#include "instrument.hpp"
#include "partitionglobale.hpp"
#include "note.hpp"
#include "music_line.hpp"
#include "gui_note.hpp"

class UI {
private:
	PartitionGlobale partition;
	GameWindow* window;

public:
	UI(PartitionGlobale partition);
	~UI();

	void Draw();

	void startPartition();

	void startStream();

	std::string getUsername();
};
