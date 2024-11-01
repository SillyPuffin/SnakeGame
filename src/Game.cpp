#include "classes.h"


using std::cout;


Game::Game(int cellCount) :
    snake(Snake()),
    food(Food(cellCount,snake.body)),
    lastUpdateTime(0),
    running(true)
{}

void Game::Draw(int cellSize,int offset, Color darkGreen) {
	food.Draw(cellSize, offset);
	snake.Draw(cellSize,offset, darkGreen);
}

void Game::Update(int cellCount)
{
    if (running)
    {
        snake.update();
        checkCollisionWithFood(cellCount);
        checkCollisionWithEdges(cellCount);
        checkCollisionWithTail(cellCount);
    }
        
}

bool Game::eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void Game::gameOver(int cellCount)
{
    snake.reset();
    food.position = food.GenerateRandomPos(cellCount, snake.body);
    running = false;
}

void Game::checkCollisionWithFood(int cellCount)
{
    if (Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.GenerateRandomPos(cellCount, snake.body);
        snake.addSegment = true;
    }
}

void Game::checkCollisionWithTail(int cellCount)
{
    std::deque<Vector2> headless = snake.body;
    headless.pop_front();

    if (food.elementInDeck(snake.body[0], headless))
    {
        gameOver(cellCount);
    }

}

void Game::checkCollisionWithEdges(int cellCount)
{
    if (snake.body[0].x == cellCount || snake.body[0].x == -1)
    {
        gameOver(cellCount);
    }
    if (snake.body[0].y == cellCount || snake.body[0].y == -1)
    {
        gameOver(cellCount);
    }

}

