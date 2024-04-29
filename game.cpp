#include "game.hpp"

Game::Game() {

}

Game::~Game() {

}

void Game::Draw() {
    spaceship.Draw();
}

void Game::HandleInput() {
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        spaceship.MoveLeft();
    } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        spaceship.MoveRight();
    }
}