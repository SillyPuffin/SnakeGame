#include "classes.h"

Food::Food(int cellCount, std::deque<Vector2> body)
{
    Image image = LoadImage("assets/Graphics/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = GenerateRandomPos(cellCount, body);
}

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::Draw(int cellSize,int offset)
{
    DrawTexture(texture, position.x * cellSize+offset, position.y * cellSize+offset, WHITE);
}

bool Food::elementInDeck(Vector2 element, std::deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}

Vector2 Food::GenerateRandomPos(int cellCount, std::deque<Vector2> body)
{
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    Vector2 position = { x,y };
    while (elementInDeck(position, body))
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        position = Vector2{ x,y };
    }
    return position;
}

