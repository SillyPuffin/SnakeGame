#include "classes.h"



void Snake::Draw(int cellSize,int offset, Color darkGreen)
{
	for (unsigned int i = 0; i < body.size(); i++)
	{
		float x = body[i].x * cellSize+offset;
		float y = body[i].y * cellSize+offset;
		float width = cellSize;
		float height = cellSize;

		Rectangle segment = { x,y, width, height };
		DrawRectangleRounded(segment, 0.5, 20 ,darkGreen);
	}
}

void Snake::update()
{
	body.push_front(Vector2Add(body[0], direction));
	if (addSegment == true)
	{
		addSegment = false;
	}
	else
	{
		body.pop_back();
	}

	
}

Snake::Snake()
{
	body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	direction = { 1,0 };
	addSegment = false;
}

void Snake::reset()
{
	body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	direction = { 1,0 };
	addSegment = false;
}
