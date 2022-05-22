#ifndef MAIN_CPP_SNAKEFOOD_H
#define MAIN_CPP_SNAKEFOOD_H
#include <vector>

class SnakeFood {
    int FoodX, FoodY;
public:
    SnakeFood(int height, int width);
    SnakeFood();
    int getSnakeFoodX();
    int getSnakeFoodY();
    void randomSnakeFood(int height, int width);
};




#endif //MAIN_CPP_SNAKEFOOD_H
