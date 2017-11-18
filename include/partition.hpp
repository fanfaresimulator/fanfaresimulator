#pragma once

#include <iostream>

#include <notes.hpp>

class Partition {
private:
	std::initializer_list <Note> listOfNotes;

public:
	std::initializer_list <Note> getNotes();
};