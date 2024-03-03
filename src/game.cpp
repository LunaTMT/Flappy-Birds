#include "game.h"
#include <iostream>
#include <string>

Game::Game() : window(sf::VideoMode(600, 600), "SFML Tube Example"), bird(*this) {
    initialiseImages();
    initialiseObstacles();

    if (!font.loadFromFile("assets/fonts/score.ttf")) {
        std::cout << "ERROR NO FONT";
    }
    
    score = 0;
    score_text.setFont(font);
    score_text.setString(std::to_string(score));
    score_text.setCharacterSize(64);
    score_text.setFillColor(sf::Color::White);
    score_text.setPosition((SCREEN_WIDTH - score_text.getLocalBounds().width) / 2.0f, 50);
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

        if (!bird.getIsAlive() && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))){
            bird.setDefaultPosition();
            bird.revive();
            score = 0;
            clearObstacles();
            initialiseObstacles();

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

        if (bird.getPosition().x > obstacle.getPosition().x && !obstacle.beenPassed){
            obstacle.beenPassed = true;
            score += 1;
        }

        if (obstacle.isOutOfBounds()) {
            obstaclesQueue.pop_front();
            obstaclesQueue.emplace_back(SCREEN_WIDTH + 150, getRandomInt(50, SCREEN_HEIGHT - 50));
        }
    }

    //updating score position and value
    score_text.setString(std::to_string(score));
    score_text.setPosition((SCREEN_WIDTH - score_text.getLocalBounds().width) / 2.0f, 50);
}

void Game::render() {
    window.clear();

    window.draw(backgroundSprite);

    for (Obstacle& obstacle : obstaclesQueue) 
        obstacle.draw(window);
    
    bird.draw(window);
    window.draw(score_text);
    window.display();
}


void Game::clearObstacles(){
    obstaclesQueue.clear();
}

void Game::initialiseObstacles() {
    obstaclesQueue.emplace_back(100.0f + SCREEN_WIDTH, CENTER_Y);
    obstaclesQueue.emplace_back(300.0f + SCREEN_WIDTH, CENTER_Y + 50.0f);
    obstaclesQueue.emplace_back(500.0f + SCREEN_WIDTH, CENTER_Y - 50.0f);
    obstaclesQueue.emplace_back(700.0f + SCREEN_WIDTH, CENTER_Y);
}


void Game::initialiseImages() {
    // Load Background Image
    if (!backgroundTexture.loadFromFile("assets/images/background-night.png")) {
        std::cout << "No background Image";
    }

    backgroundSprite.setTexture(backgroundTexture);
}
