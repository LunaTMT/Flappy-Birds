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
    void stopObstacleMovement();

private:
    void handleEvents();
    void update(float deltaTime);
    void render();

    int score;    

    void clearObstacles();
    void initialiseObstacles();
    
private:
    Player bird;
    std::deque<Obstacle> obstaclesQueue;
    sf::RenderWindow window;

    sf::Font font;
    sf::Text score_text;
};

#endif // GAME_H
