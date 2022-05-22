#include "SnakeFood.h"
#include <iostream>
#include "Snake.h"
#include "SnakeBoard.h"
#include <cstdlib>

using namespace std;

SnakeFood::SnakeFood(int height, int width)
{
    randomSnakeFood(height, width);
}
SnakeFood::SnakeFood()
{
}
int SnakeFood::getSnakeFoodY()
{
    return FoodY;
}
int SnakeFood::getSnakeFoodX()
{
    return FoodX;
}
void SnakeFood::randomSnakeFood(int height, int width)
{
    FoodY=rand()%(height - 2) + 1;
    FoodX=rand()%(width - 2) + 1;
}

