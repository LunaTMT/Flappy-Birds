// Player.cpp
#include "Player.h"
#include "globals.h"
#include <iostream>

Player::Player(float initialX, float initialY) : jumpStrength(-400.0f) {
    shape.setSize(sf::Vector2f(50, 50));
    shape.setPosition(initialX, initialY);
    shape.setFillColor(sf::Color::Green);

    velocityY = 0.0f;
    accelerationY = 1500.0f;
    isJumpKeyPressed = false;
}

void Player::update(float deltaTime) {
    // Apply gravity
    velocityY += accelerationY * deltaTime;

    // Apply vertical velocity
    shape.move(0, velocityY * deltaTime);

    // Check if the player is on the ground
    if (shape.getPosition().y + shape.getSize().y >= SCREEN_HEIGHT) {
        shape.setPosition(shape.getPosition().x, SCREEN_HEIGHT - shape.getSize().y);
        velocityY = 0.0f;  // Reset velocity when on the ground
        canJump = true;    // Allow jumping when on the ground
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
void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::jump() { velocityY = jumpStrength; }


sf::FloatRect Player::getBoundingBox() const {
    return shape.getGlobalBounds();
}


bool Player::collidesWith(const sf::FloatRect& otherBoundingBox) const {
    return getBoundingBox().intersects(otherBoundingBox);
}