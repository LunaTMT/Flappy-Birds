#include "game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "SFML Tube Example"), bird(CENTER_X, CENTER_Y) {
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
            stopObstacleMovement();
        }
    }

    // Additional game logic...

    for (Obstacle& obstacle : obstaclesQueue) {
        if (obstacle.isOutOfBounds()) {
            std::cout << "OOB";
            obstaclesQueue.pop_front();
            obstaclesQueue.emplace_back(SCREEN_WIDTH + 50, getRandomInt(150, SCREEN_HEIGHT - 150));
        }
    }
}

void Game::render() {
    window.clear();

    

    for (Obstacle& obstacle : obstaclesQueue) {
        obstacle.draw(window);
    }

    // Draw game elements...
    bird.draw(window);

    window.display();
}




void Game::stopObstacleMovement() {
    for (Obstacle& obstacle : obstaclesQueue) {
        obstacle.stopMoving();
    }
}

void Game::initialiseObstacles() {
    obstaclesQueue.emplace_back(100.0f + SCREEN_WIDTH, 250.0f);
    obstaclesQueue.emplace_back(300.0f + SCREEN_WIDTH, 300.0f);
    obstaclesQueue.emplace_back(500.0f + SCREEN_WIDTH, 450.0f);
    obstaclesQueue.emplace_back(700.0f + SCREEN_WIDTH, 500.0f);
}
