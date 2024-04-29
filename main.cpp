#include <iostream>
#include <raylib.h>
//#include "spaceship.hpp"
#include "game.hpp"
#include "laser.hpp"

using namespace std;

int main () {
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "C++ Space Invaders");
    SetTargetFPS(60);

    //Spaceship spaceship;
    Game game;
    Laser laser = Laser({100, 100}, 7);

    while(WindowShouldClose() == false) {

        game.HandleInput();

        BeginDrawing();
        ClearBackground(grey);
        //spaceship.Draw();
        game.Draw();
        laser.Draw();
        EndDrawing();
    }

    CloseWindow();
}