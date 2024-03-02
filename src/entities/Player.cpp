#include "Player.h"
#include "Obstacle.h"
#include "game.h"  // Include the header file for Game
#include "globals.h"
#include <iostream>



Player::Player(float initialX, float initialY, Game& game) : jumpStrength(-400.0f), game(&game) {
    shape.setSize(sf::Vector2f(50, 50));
    shape.setPosition(initialX - getSize().x / 2, initialY - getSize().y / 2);
    shape.setFillColor(sf::Color::Green);

    velocityY = 0.0f;
    accelerationY = 1500.0f;
    isJumpKeyPressed = false;
    canJump = true;
    isAlive = true;
    hasCollidedWithObstacle = false;
}


void Player::update(float deltaTime) {
    if (isAlive) {
        // Apply gravity
        velocityY += accelerationY * deltaTime;

        // Apply vertical velocity
        shape.move(0, velocityY * deltaTime);

        checkIfTouchingGround();
        checkIfTouchingTop();
        checkJump();
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Player::collidesWith(const sf::FloatRect& rect) const {
    return shape.getGlobalBounds().intersects(rect);
}

bool Player::collidesWith(const Obstacle& obstacle) const {
    auto BBs = obstacle.getBoundingBoxes();
    sf::FloatRect BB = BBs.first;
    sf::FloatRect TB = BBs.second;
    return collidesWith(BB) || collidesWith(TB);
}

void Player::checkIfTouchingGround() {
    if (shape.getPosition().y + shape.getSize().y >= SCREEN_HEIGHT) {
        setColour(sf::Color::Red);
        kill();
        velocityY = 0.0f;  // Reset velocity when on the ground
        game->stopObstacleMovement();  // Access the Game class function
    }
}

void Player::checkIfTouchingTop() {
    float y = shape.getPosition().y;
    if (y < 0)
        shape.move(0, -y);
}

void Player::checkJump() {
    if (!hasCollidedWithObstacle){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!isJumpKeyPressed && canJump) {
                jump();
                isJumpKeyPressed = true;
                canJump = false;
            }
        } else {
            isJumpKeyPressed = false;
            canJump = true;  
        }
    }
}

bool Player::getIsAlive() const {
    return isAlive;
}

sf::Vector2f Player::getSize() const {
    return shape.getSize();
}


void Player::setColour(const sf::Color& colour) {
    shape.setFillColor(colour);
}

void Player::sethasCollidedWithObstacle(bool boolean){
    hasCollidedWithObstacle = boolean;
}

void Player::kill() {
    isAlive = false;
}

void Player::jump() {
    velocityY = jumpStrength;
}
