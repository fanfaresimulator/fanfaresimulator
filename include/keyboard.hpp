#pragma once

enum Switch {
  START = 0,
  END = 1,
};

class Keyboard {
public:
    Keyboard();

    ~Keyboard();

    Note getNextNote();
};
