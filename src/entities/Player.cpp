#include "Player.h"
#include "Obstacle.h"
#include "globals.h"
#include <iostream>

Player::Player(float initialX, float initialY) : jumpStrength(-400.0f) {
    shape.setSize(sf::Vector2f(50, 50));
    shape.setPosition(initialX, initialY);
    shape.setFillColor(sf::Color::Green);


    velocityY = 0.0f;
    accelerationY = 1500.0f;
    isJumpKeyPressed = false;
    isAlive = true;
}

void Player::update(float deltaTime) {
    if (isAlive){
        // Apply gravity
        velocityY += accelerationY * deltaTime;

        // Apply vertical velocity
        shape.move(0, velocityY * deltaTime);

        // Check if the player is on the ground
        if (shape.getPosition().y + shape.getSize().y >= SCREEN_HEIGHT) {

            //shape.setPosition(shape.getPosition().x, SCREEN_HEIGHT - shape.getSize().y);
            velocityY = 0.0f;  // Reset velocity when on the ground
            isAlive = false;
        }

        // Handle jumping
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!isJumpKeyPressed && canJump) {
                jump();
                isJumpKeyPressed = true;
                canJump = false;
            }
        } else {
            isJumpKeyPressed = false;
            canJump = true; // Allow jumping again when the space key is released
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::jump() {
    velocityY = jumpStrength;
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


bool Player::getIsAlive() const{
    return isAlive;
}

void Player::setColour(const sf::Color& colour) {
    shape.setFillColor(colour);
}

void Player::kill(){
    isAlive = false;
}

void Player::disableJumping(){
    canJump=false;
}