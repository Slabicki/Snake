#include "SnakeBoard.h"
#include <iostream>
#include "Snake.h"
#include "SnakeFood.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;
SnakeBoard::SnakeBoard(int width, int height, GameMode mode)  {

    this->height=height;
    this->width=width;
    this->mode=mode;
    result=0;
    state=RUNNING;
    snake=Snake(height/5, width/5);
    fruit=SnakeFood(height, width);
    srand(time(NULL));

    Wall1Texture.loadFromFile("../Textures/wall1.png");
    Wall1.setTexture(Wall1Texture);
    Wall2Texture.loadFromFile("../Textures/wall2.png");
    Wall2.setTexture(Wall2Texture);
    SnakesHeadTexture.loadFromFile("../Textures/SnakesHead1.png");
    SnakesHead.setTexture(SnakesHeadTexture);
    SnakesBodyTexture.loadFromFile("../Textures/SnakesBody1.png");
    SnakesBody.setTexture(SnakesBodyTexture);
    FruitsTexture.loadFromFile("../Textures/fruit.png");
    Fruits.setTexture(FruitsTexture);

    font.loadFromFile("../Textures/Montserrat-Light.ttf");
    Result.setFont(font);
    Result.setCharacterSize(30);
    Result.setFillColor(sf::Color::White);
    Defeat.setFont(font);
    Defeat.setCharacterSize(25);
    Defeat.setFillColor(sf::Color::Red);
/*
    switch (mode){
        case SLOW:
            speed = 100000;
            break;
        case NORMAL:
            speed = 200000;
            break;
        case FAST:
            speed = 300000;
            break;
    }*/
}
void SnakeBoard::debug_display(sf::RenderWindow& window)
{

    for (int i=0; i<=height-1; i++)
    {
        //cout <<"#";
        Wall1.setPosition(160+30*i, 160);            // gdzie ma byc sciana
        window.draw(Wall1);                            // narysowanie

        for (int j=1; j<width-1; j++)
        {
            if (i==0)
            {
                //cout<<"#";
                Wall2.setPosition(160, 160+30*j);             // gdzie ma byc sciana
                window.draw(Wall2);                         // narysowanie
            }
            else if (i==height-1)
            {
                //cout<<"#";
                Wall2.setPosition((i+5)*30, 160+30*j);             // gdzie ma byc sciana
                window.draw(Wall1);                                // narysowanie
            }
            else if (i==snake.getSnakeHeadY() && j==snake.getSnakeHeadX())
            {
                //cout<<"X";
                SnakesHead.setPosition((160+30 *j), (160+30*i));             // gdzie ma byc waz
                window.draw(SnakesHead);                                    // narysowanie
            }
            else if (i==fruit.getSnakeFoodX() && j==fruit.getSnakeFoodY())
            {
                //cout<<"F";
                Fruits.setPosition((160+30*j), (160+30*i));       // ustawienie pozycji
                window.draw(Fruits);                                 // narysowanie
            }
            else {
                //string toDisplay = " ";
                for (int x=0; x<snake.getTail().size(); x++)
                {
                    if (snake.getTail()[x][0] == j && snake.getTail()[x][1] == i)
                    {
                        //toDisplay="x";
                        SnakesBody.setPosition((180+30*j), (180+30*i));
                        window.draw(SnakesBody);
                    }
                }
                //cout<<toDisplay;
            }
        }
        Wall1.setPosition(160+30*i, (height+1) * 30); //ustawienie sciany
        window.draw(Wall1);
    }
    //cout<<snake.getSnakeHeadX()<< " " <<snake.getSnakeHeadY()<<endl;
    //cout<<SnakeLive()<<endl;
}
void SnakeBoard::display(sf::RenderWindow& window)
{
    for (int i=0; i<=height-1; i++)
    {
        Wall1.setPosition(160+30*i, 160);
        window.draw(Wall1);

        for (int j=1; j<width-1; j++)
        {
            if (i == 0)
            {
                Wall2.setPosition(160, 160+30*j);
                window.draw(Wall2);
            }
            else if (i == height-1)
            {
                Wall2.setPosition((i+2)*39.2, 160+30*j);
                window.draw(Wall2);
            }
            else if (i==snake.getSnakeHeadY() && j==snake.getSnakeHeadX())
            {
                SnakesHead.setPosition((160+30*j), (160+30*i));
                window.draw(SnakesHead);
            }
            else if (i==fruit.getSnakeFoodY() && j==fruit.getSnakeFoodX())
            {
                Fruits.setPosition((160+30*j), (160+30*i));
                window.draw(Fruits);
            }
            else
            {
                for (int x=0; x<snake.getTail().size(); x++)
                {
                    if (snake.getTail()[x][0] == j && snake.getTail()[x][1] == i) {
                        SnakesBody.setPosition((160+30*j), (160+30*i));
                        window.draw(SnakesBody);
                    }
                }
            }
        }
        Wall1.setPosition(160+30*i, (height+1)*39.5);
        window.draw(Wall1);
    }
}
void SnakeBoard::handleEvent(sf::Event& event, sf::RenderWindow& window, sf::Clock &clk) {

    sf::Time time;
    time = clk.getElapsedTime();
    switch (mode){
        case SLOW:if (clk.getElapsedTime().asSeconds()>0.75)
            {
                snake.automaticMove();
                clk.restart();
            }

            break;
        case NORMAL:
            if (clk.getElapsedTime().asSeconds()>0.5)
            {
                snake.automaticMove();
                clk.restart();
            }

            break;
        case FAST:
            if (clk.getElapsedTime().asSeconds()>0.25)
            {
                snake.automaticMove();
                clk.restart();
            }

            break;
    }
    if (clk.getElapsedTime().asSeconds() > 0.1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            snake.moveW();
            clk.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            snake.moveS();
            clk.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            snake.turnLEFT();
            clk.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            snake.turnRIGHT();
            clk.restart();
        }
    }
}
SnakeBoard::SnakeBoard()
{

}
void SnakeBoard::play() {
    snake.getTail();
    countResult();
    update();
}
int SnakeBoard::getBoardHeight() const{
    return height;
}
int SnakeBoard::getBoardWidth() const{
    return width;
}
/*
int SnakeBoard::getSpeed() const {
    return speed;
}
bool SnakeBoard::inBoard(int row, int col) const{

    if (row<0 && row>height && col<0 && col>width)
    {
        return false;
    }
    return true;
}*/
int SnakeBoard::getGameState()
{
    return state;
}
void SnakeBoard::update() //kontroluje by owoc nie byl narysowany na wezu
{
    for (int x = 0; x < snake.getTail().size(); x++)
    {
        while ((snake.getSnakeHeadX() == fruit.getSnakeFoodX() && snake.getSnakeHeadY() == fruit.getSnakeFoodY()) ||
               (snake.getTail()[x][0]==fruit.getSnakeFoodX() && snake.getTail()[x][1] == fruit.getSnakeFoodY()))
        {
            fruit.randomSnakeFood(height, width);
        }
    }
}
bool SnakeBoard::SnakeLive()  // czy snake nie zderzyl sie ze soba
{
    for (int x=0; x<snake.getTail().size(); x++)
    {
        if ((snake.getSnakeHeadY() <= 0 || snake.getSnakeHeadY() >= height - 1 || snake.getSnakeHeadX() <= 0 || snake.getSnakeHeadX() >= width - 1) ||
            (snake.getSnakeHeadX()==snake.getTail()[x][0] && snake.getSnakeHeadY()==snake.getTail()[x][1]))
        {
            return false;
        }
    }
    return true;
}
int SnakeBoard::countResult()
{

    if (snake.getSnakeHeadX()==fruit.getSnakeFoodX() && snake.getSnakeHeadY()==fruit.getSnakeFoodY())
    {
        result=result+1;
        snake.grow();
    }
    return result;
}
void SnakeBoard::uDefeat(sf::RenderWindow& window)
{
    if (!SnakeLive())
    {
        Defeat.setPosition((getBoardWidth()) * 20, getBoardHeight() * 10);
        Defeat.setString("DEFEAT, HIT THE WALL!");
        window.draw(Defeat);
    }
}

void SnakeBoard::showResult(sf::RenderWindow& window)
{
    ostringstream ssResult;
    ssResult<<"Result:"<<result;
    Result.setPosition(getBoardWidth()*30, 30);
    Result.setString(ssResult.str());
    window.draw(Result);
}
