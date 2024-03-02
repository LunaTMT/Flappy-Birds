#include "game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(600, 600), "SFML Tube Example"), bird(CENTER_X, CENTER_Y, *this) {
    initialiseObstacles();
}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        handleEvents();
        update(clock.restart().asSeconds());
        render();
    }
}

void Game::stopObstacleMovement() {
    for (Obstacle& obstacle : obstaclesQueue) {
        obstacle.stopMoving();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update(float deltaTime) {
    bird.update(deltaTime);

    for (Obstacle& obstacle : obstaclesQueue) {
        obstacle.update(deltaTime);

        if (bird.collidesWith(obstacle)) {
            bird.setColour(sf::Color::Red);
            bird.sethasCollidedWithObstacle(true);
            stopObstacleMovement();
        }
    }

    // Additional game logic...

    for (Obstacle& obstacle : obstaclesQueue) {
        if (obstacle.isOutOfBounds()) {
            obstaclesQueue.pop_front();
            obstaclesQueue.emplace_back(SCREEN_WIDTH + 150, getRandomInt(50, SCREEN_HEIGHT - 50));
        }
    }
}

void Game::render() {
    window.clear();

    for (Obstacle& obstacle : obstaclesQueue) 
        obstacle.draw(window);
    
    bird.draw(window);
    window.display();
}

void Game::initialiseObstacles() {
    obstaclesQueue.emplace_back(100.0f + SCREEN_WIDTH, CENTER_Y);
    obstaclesQueue.emplace_back(300.0f + SCREEN_WIDTH, CENTER_Y + 50.0f);
    obstaclesQueue.emplace_back(500.0f + SCREEN_WIDTH, CENTER_Y - 50.0f);
    obstaclesQueue.emplace_back(700.0f + SCREEN_WIDTH, CENTER_Y);
}
