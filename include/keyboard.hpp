#pragma once

//
// Created by Luis Gustavo on 21/11/2017
//

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
