#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include "Player.h"
#include "globals.h"
#include "utilities.h"

#include <iostream>
#include <random>
#include <deque>


void stopObstacleMovement(std::deque<Obstacle>& obstaclesQueue) {
    for (Obstacle& obstacle : obstaclesQueue) {
        obstacle.stopMoving();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tube Example");


    std::deque<Obstacle> obstaclesQueue;
    obstaclesQueue.emplace_back(100.0f + SCREEN_WIDTH, 250.0f);
    obstaclesQueue.emplace_back(300.0f + SCREEN_WIDTH, 300.0f);
    obstaclesQueue.emplace_back(500.0f + SCREEN_WIDTH, 450.0f);
    obstaclesQueue.emplace_back(700.0f + SCREEN_WIDTH, 500.0f);
    
    Player bird(CENTER_X, CENTER_Y);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Get the elapsed time since the last frame
        sf::Time deltaTime = clock.restart();
        float dtSeconds = deltaTime.asSeconds();

        // Update the game state with delta time
        bird.update(dtSeconds);
        
        for (Obstacle& obstacle : obstaclesQueue) {
            obstacle.update(dtSeconds);

            if (bird.collidesWith(obstacle)) 
                bird.kill();
            
        }

        if (!bird.getIsAlive()){
            bird.setColour(sf::Color::Red);
            stopObstacleMovement(obstaclesQueue);
        }

        // --------------------------------------

        window.clear();

        //Draw
        bird.draw(window);
        
        for (Obstacle& obstacle : obstaclesQueue) {
            obstacle.draw(window);
            if (obstacle.isOutOfBounds()) {
                obstaclesQueue.pop_front();
                obstaclesQueue.emplace_back(SCREEN_WIDTH + 50, getRandomInt(150, SCREEN_HEIGHT - 150));
            }
        }

        window.display();
        // --------------------------------------
    }

    return 0;
}


