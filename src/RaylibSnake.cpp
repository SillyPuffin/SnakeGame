// RaylibSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>

//classes definitions
#include "classes.h"

using std::cout;

Color green = { 173,204,96,255 };
Color darkGreen = { 43,51,24,255 };

int cellSize = 30;
int cellCount = 25;
int offset = 75;

int main() {

    cout << "starting game engine..." << "\n";
    InitWindow(2*offset+cellSize*cellCount, 2*offset+cellSize*cellCount, "retro-snake");
    SetTargetFPS(60);

    Game game = Game(cellCount);

    while (WindowShouldClose() == false) {
        BeginDrawing();

        if (game.eventTriggered(0.2))
        {
            //upadtingadkfjasklfjasdlkfjASDLKFJASD;FLKJ
            game.Update(cellCount);
        }
        
        //movement
        if (IsKeyPressed(KEY_W) && game.snake.direction.y != 1)
        {
            game.snake.direction = { 0,-1 };
        }
        else if (IsKeyPressed(KEY_S) && game.snake.direction.y != -1)
        {
            game.snake.direction = { 0,1 };
        }
        else if (IsKeyPressed(KEY_A) && game.snake.direction.x != 1)
        {
            game.snake.direction = { -1,0 };
        }
        else if (IsKeyPressed(KEY_D) && game.snake.direction.x != -1)
        {
            game.snake.direction = { 1,0 };
        }

        //restart game
        if (game.running == false && IsKeyPressed(KEY_SPACE))
        {
            game.running = true;
        }
        

        //drawing
        ClearBackground(green);
        game.Draw(cellSize,offset, darkGreen);
        DrawRectangleLinesEx(Rectangle{ (float)offset - 5,(float)offset - 5,(float)cellSize * cellCount + 10,(float)cellSize * cellCount + 10 },5, darkGreen);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
