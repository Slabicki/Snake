//
// Created by huber on 11.05.2022.
//
#ifndef MAIN_CPP_SNAKE_H
#define MAIN_CPP_SNAKE_H
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
//#include "SnakeBoard.h"

using namespace std;

enum Direction {UP, DOWN, LEFT, RIGHT};


class Snake
{
    int headX, headY;
    int size;
    vector<vector<int>>tail;
    Direction direction;

public:
    Snake(int headX, int headY);
    Snake();
    int getSnakeHeadX();
    int getSnakeHeadY();
    int move();
    int moveS();
    int moveW();
    int turnLEFT();
    int turnRIGHT();
    int automaticMove();
    vector<vector<int>>getTail();
    void grow(); // rosniecie weza

};


#endif //MAIN_CPP_SNAKE_H
