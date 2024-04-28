#include <iostream>
#include <raylib.h>
//#include "spaceship.hpp"
#include "game.hpp"

using namespace std;

int main () {
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "C++ Space Invaders");
    SetTargetFPS(60);

    //Spaceship spaceship;
    Game game;

    while(WindowShouldClose() == false) {

        game.HandleInput();

        BeginDrawing();
        ClearBackground(grey);
        //spaceship.Draw();
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}