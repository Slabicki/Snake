#include <iostream>
#include "SFML/Graphics.hpp"
#include "SnakeBoard.h"
#include "Snake.h"
#include "SnakeFood.h"
using namespace std;
/*
int main() {
    sf::RenderWindow win(sf::VideoMode(800, 600), "Snake");

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        win.clear();
        win.display();
    }
    return 0;
}*/
int main()
{
    SnakeBoard Board(10, 10, NORMAL);
    sf::RenderWindow win(sf::VideoMode(800, 600), "Snake");
    win.setFramerateLimit(80);
    sf::Clock clk;
    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
                continue;
            }
        }
        while (Board.SnakeLive())
        {
            win.clear(sf::Color (0,0,0,0));
            Board.showResult(win);
            Board.display(win);
            Board.play();
            Board.handleEvent(event, win, clk);
            Board.uDefeat(win);
            win.display();
        }
    }
}