#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include "Player.h"
#include "globals.h"
#include "utilities.h"

#include <deque>

class Game {
public:
    Game();

    void run();

private:
    void handleEvents();
    void update(float deltaTime);
    void render();

    void stopObstacleMovement();
    void initialiseObstacles();

private:
    Player bird;
    std::deque<Obstacle> obstaclesQueue;
    sf::RenderWindow window;
};

#endif // GAME_H
