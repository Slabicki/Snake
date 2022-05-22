//
// Created by huber on 11.05.2022.
//
#include <iostream>
#include "Snake.h"
#include "SFML/Graphics.hpp"
#include <vector>
using namespace std;

Snake::Snake(int headY, int headX)
{
    this->headY=headY;
    this->headX=headX;
    tail.push_back(vector<int>({ headX, headY+1}));
    size=1;
    direction=DOWN;
}

Snake::Snake()
{
}

int Snake::getSnakeHeadX()
{
    return headX;
}
int Snake::getSnakeHeadY()
{
    return headY;
}
void Snake::grow()
{
    size=size+1;
}
vector<vector<int>>Snake::getTail()
{
    return tail;
}

int Snake::move()
{
    int prevX = headX;
    int prevY = headY;
    bool ismoving = 0;

    char x;
   cin >> x;
    switch (x)
    {
        case 'w':
            if (direction != DOWN)
            {
                headY=headY-1;
                direction=UP;
                ismoving=1;
            }
            break;
        case 's':
            if (direction != UP)
            {
                headY=headY+1;
                direction=DOWN;
                ismoving=1;
            }
            break;
            case 'd':
            if (direction != LEFT)
            {
                headX=headX+1;
                direction=RIGHT;
                ismoving=1;
            }
            break;
        case 'a':
            if (direction != RIGHT)
            {
                headX=headX-1;
                direction=LEFT;
                ismoving=1;
            }
            break;
    }
    if(ismoving){
        if (size=tail.size())
        {
            tail.pop_back(); //usuwanie ostatniego elementu z wektotora tail
        }

        vector<vector<int>>::iterator it=tail.begin(); //rosniecie ogonko
        tail.insert(it, vector<int>({ prevX, prevY }));
    }
    return headX, headY;
}
int Snake::moveS()
{
    int prevX=headX;
    int prevY=headY;
    if(direction != UP)
    {
        if(direction != DOWN)
        {
            bool ismoving=0;
            direction=DOWN;
            ismoving=1;
            headY=headY+1;
            if(ismoving) {
                if(size==tail.size())
                {
                    tail.pop_back();
                }

                vector<::vector<int>>::iterator it=tail.begin();
                tail.insert(it, vector<int>({ prevX, prevY }));
            }
            return headX, headY;
        }
    }
}
int Snake::moveW()
{
    int prevX=headX;
    int prevY=headY;
    if(direction != DOWN)
    {
        if(direction != UP)
        {
            bool ismoving=0;
            direction=UP;
            ismoving=1;
            headY=headY-1 ;
            if(ismoving)
            {
                if (size==tail.size())
                {
                    tail.pop_back();
                }
                vector<vector<int>>::iterator it=tail.begin();
                tail.insert(it, vector<int>({ prevX, prevY }));
            }
            return headX, headY;
        }
    }
}
int Snake::turnLEFT()
{
    int prevX=headX;
    int prevY=headY;
    if (direction != RIGHT)
    {
        if (direction != LEFT)
        {
            bool ismoving=0;
            direction = LEFT;
            ismoving=1;
            headX=headX-1;
            if (ismoving) {
                if (size==tail.size())
                {
                    tail.pop_back();
                }
                vector<vector<int>>::iterator it=tail.begin();
                tail.insert(it, vector<int>({ prevX, prevY }));
            }
            return headX, headY;
        }
    }
}
int Snake::turnRIGHT()
{
    int prevX=headX;
    int prevY=headY;
    if (direction != RIGHT)
    {
        if (direction != LEFT)
        {
            bool ismoving=0;
            direction=RIGHT;
            ismoving=1;
            headX=headX+1;

            if (ismoving) {
                if (size == tail.size())
                {
                    tail.pop_back(); //usuwanie ostatniego elementu
                }
                vector<vector<int>>::iterator it=tail.begin();
                tail.insert(it, vector<int>({ prevX, prevY }));
            }
            return headX, headY;
        }
    }
}
int Snake::automaticMove()
{
    int prevX=headX;
    int prevY=headY;
    bool shouldMove=1;
    if (direction == LEFT)
    {
        shouldMove = 1;
        headX = headX - 1;
    }
    if (direction == RIGHT)
    {
        shouldMove = 1;
        headX = headX + 1;
    }
    if (direction == UP)
    {
        shouldMove = 1;
        headY = headY - 1;
    }
    if (direction == DOWN)
    {
        shouldMove = 1;
        headY = headY + 1;
    }

    if (shouldMove) {
        if (size == tail.size())
        {
            tail.pop_back();
        }
        vector<vector<int>>::iterator it=tail.begin();
        tail.insert(it, vector<int>({ prevX, prevY }));
    }
    return headX, headY;
}

