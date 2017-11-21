//
// Created by Luis Gustavo on 21/11/2017
//

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

enum Switch {
    START = 0,
    END = 1,
};

class Keyboard {
public:
    Keyboard();

    ~Keyboard();

    void getNextNote();
};

#endif // KEYBOARD_HPP