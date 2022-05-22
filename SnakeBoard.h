#include <iostream>
#include "Snake.h"
#include "SnakeFood.h"
#include "SFML/Graphics.hpp"
#include <vector>


#ifndef MAIN_CPP_SNAKEBOARD_H
#define MAIN_CPP_SNAKEBOARD_H


enum GameMode {SLOW,NORMAL,FAST};
enum GameState {RUNNING, FINISHED_LOSS};
/*
struct field {
    bool wall;
    bool Food;
    bool Snakes;
};
*/
class SnakeBoard{
    //field board[100][100];
    int height;
    int width;
    int result;
    //int speed;
    Snake snake;
    SnakeFood fruit;
    GameMode mode;
    GameState state;

    sf::Texture Wall1Texture;
    sf::Sprite Wall1;
    sf::Texture Wall2Texture;
    sf::Sprite Wall2;
    sf::Texture SnakesHeadTexture;         // buzia weza
    sf::Sprite SnakesHead;
    sf::Texture SnakesBodyTexture;         // cialo weza
    sf::Sprite SnakesBody;
    sf::Texture FruitsTexture;
    sf::Sprite Fruits;
    sf::Font font;
    sf::Text Result;
    sf::Text Defeat;

public:
    //void debug_display() const;
    SnakeBoard();
    SnakeBoard(int width, int height, GameMode mode);
    int getBoardWidth() const;
    int getBoardHeight() const;
    void debug_display(sf::RenderWindow& window);
    void display(sf::RenderWindow& window);
    void handleEvent(sf::Event& event, sf::RenderWindow& window, sf::Clock &clk);
    int getSpeed() const;
    int getGameState();
    //bool inBoard(int row, int col) const;
    void play();
    void update();
    bool SnakeLive();
    int countResult();
    void uDefeat(sf::RenderWindow& window);
    void showResult(sf::RenderWindow& window);

};

#endif //MAIN_CPP_SNAKEBOARD_H




