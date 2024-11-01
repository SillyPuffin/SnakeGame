#pragma once
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include <iostream>

class Food
{
public:
    Vector2 position;
    Texture2D texture;

    Food(int cellCount, std::deque<Vector2> body);

    ~Food();

    void Draw(int cellSize, int offset);

    Vector2 GenerateRandomPos(int cellCount, std::deque<Vector2> body);
    bool elementInDeck(Vector2 element, std::deque<Vector2> deque);

};

class Snake
{
public:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment;

    Snake();
    void reset();

    void Draw(int cellSize,int offset, Color darkGreen);

    void update();

};

class Game
{
public:
    bool running;
    Snake snake;
    Food food;

    double lastUpdateTime = 0;

    Game(int cellCount);
    void Draw(int cellSize,int offset, Color darkGreen);
    void Update(int cellCount);
    void gameOver(int cellCount);

    bool eventTriggered(double interval); 
    
    void checkCollisionWithFood(int cellCount);
    void checkCollisionWithEdges(int cellCount);
    void checkCollisionWithTail(int cellCount);

};