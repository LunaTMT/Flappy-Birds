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



void Player::checkIfTouchingGround(){
    if (shape.getPosition().y + shape.getSize().y >= SCREEN_HEIGHT) {
        setColour(sf::Color::Red);
        kill();
        velocityY = 0.0f;  // Reset velocity when on the ground
    }
}

void Player::checkIfTouchingTop(){
    float y = shape.getPosition().y;
    if (y < 0)
        shape.move(0, -y);
}

void Player::checkJump(){
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



bool Player::getIsAlive() const{
    return isAlive;
}


void Player::setColour(const sf::Color& colour) {
    shape.setFillColor(colour);
}



void Player::kill(){
    isAlive = false;
}

void Player::jump() {
    velocityY = jumpStrength;
}

