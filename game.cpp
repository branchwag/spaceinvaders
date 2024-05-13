#include "game.hpp"
#include <iostream>

Game::Game() {
    obstacles = CreateObstacles();
    aliens = CreateAliens();
}

Game::~Game() {

}

void Game::Update(){
    for(auto& laser: spaceship.lasers) {
        laser.Update();
    }

    DeleteInactiveLasers();
    //std::cout << "Vector Size: " << spaceship.lasers.size() << std::endl;
}

void Game::Draw() {
    spaceship.Draw();

    for(auto& laser: spaceship.lasers) {
        laser.Draw();
    }

    for(auto& obstacle: obstacles) {
        obstacle.Draw();
    }

    for(auto& alien: aliens){
        alien.Draw();
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

void Game::DeleteInactiveLasers() {
    for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();) {
        if (!it -> active) {
            it = spaceship.lasers.erase(it);
        } else {
            ++ it;
        }
    }
}

std::vector<Obstacle> Game::CreateObstacles() {
    int obstacleWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (4 * obstacleWidth))/5;

    for(int i = 0; i < 4; i++) {
        float offsetX = (i + 1) * gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));
    }
    return obstacles;
}

std::vector<Alien> Game::CreateAliens() {
    std::vector<Alien> aliens;
    for(int row = 0; row < 5; row++) {
        for(int column = 0; column < 11; column++) {
            float x = column * 55;
            float y = row * 55;
            aliens.push_back(Alien(1, {x, y}));
        }
    }
    return aliens;
}