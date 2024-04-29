#include "game.hpp"

Game::Game() {

}

Game::~Game() {

}

void Game::Update(){
    for(auto& laser: spaceship.lasers) {
        laser.Update();
    }
}

void Game::Draw() {
    spaceship.Draw();

    for(auto& laser: spaceship.lasers) {
        laser.Draw();
    }
}

void Game::HandleInput() {
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        spaceship.MoveLeft();
    } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        spaceship.MoveRight();
    } else if (IsKeyDown(KEY_SPACE)){
        spaceship.FireLaser();
    }
}