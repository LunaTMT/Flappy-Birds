#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include "Player.h"
#include "globals.h"
#include "utilities.h"

#include <iostream>
#include <random>
#include <deque>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tube Example");


    std::deque<Obstacle> obstaclesQueue;
    obstaclesQueue.emplace_back(100.0f, 200.0f);
    obstaclesQueue.emplace_back(300.0f, 300.0f);
    obstaclesQueue.emplace_back(500.0f, 450.0f);
    obstaclesQueue.emplace_back(700.0f, 500.0f);
    
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
        
        for (Obstacle obstacle : obstaclesQueue){
            obstacle.update(dtSeconds);
        }

        window.clear();

        bird.draw(window);
        
        for (Obstacle obstacle : obstaclesQueue){
            obstacle.draw(window);
            if (obstacle.isOutOfBounds()) {
                obstaclesQueue.pop_front();
                obstaclesQueue.emplace_back(SCREEN_WIDTH+50, getRandomInt(150, SCREEN_HEIGHT-150));
            }
        }
        window.display();
    }

    return 0;
}

