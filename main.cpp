#include <iostream>
#include <raylib.h>
#include "game.hpp"

using namespace std;

int main () {
    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth + offset, windowHeight + 2 * offset, "C++ Space Invaders");
    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false) {

        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18f, 20, 2, yellow);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}