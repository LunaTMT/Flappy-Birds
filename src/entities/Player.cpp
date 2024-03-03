#include "Player.h"
#include "Obstacle.h"
#include "game.h"
#include "globals.h"
#include <iostream>

Player::Player(Game& game) : jumpStrength(-400.0f), game(&game) {
    loadAnimationFrames();

    //setDefaultTexture();
    sprite.setScale(1.5f, 1.5f);  // Adjust scale as needed
    sprite.setPosition(CENTER_X - sprite.getLocalBounds().width / 2, CENTER_Y - sprite.getLocalBounds().height / 2);

    velocityY = 0.0f;
    accelerationY = 1500.0f;
    isJumpKeyPressed = false;
    canJump = true;
    isAlive = true;
    hasCollidedWithObstacle = false;
    currentFrame = 0;  // Initialize currentFrame
    frameDuration = 0.1f;  // Adjust frame duration as needed
    elapsedTime = 0.0f;  // Initialize elapsedTime
}

void Player::update(float deltaTime) {
    if (isAlive) {
        // Apply gravity
        velocityY += accelerationY * deltaTime;

        sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);
        
        if (velocityY < 300){
            sprite.setRotation(-20);
        } else {
            sprite.setRotation((velocityY/1000) * 90);

            if (sprite.getRotation() > 90){
                sprite.setRotation(90);
            }
        }

        

        // Apply vertical velocity
        sprite.move(0, velocityY * deltaTime);

        updateAnimation(deltaTime);  // Update the animation frame
        checkIfTouchingGround();
        checkIfTouchingTop();
        checkJump();
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::loadAnimationFrames() {
    for (int i = 1; i <= 3; ++i) {
        sf::Texture frame;
        std::string filename = "assets/images/bird-frame" + std::to_string(i) + ".png";
        if (frame.loadFromFile(filename)) {
            animationFrames[i - 1] = frame;
        } else {
            std::cout << "Error loading animation frame " << i << std::endl;
        }
    }
}
void Player::updateAnimation(float deltaTime) {
    elapsedTime += deltaTime;

    // Check if enough time has passed to change frame
    if (elapsedTime >= frameDuration) {
        // Increment the current frame and reset the timer
        currentFrame = (currentFrame + 1) % animationFrames.size();
        sprite.setTexture(animationFrames[currentFrame]);
        elapsedTime = 0.0f;
    }
}

bool Player::collidesWith(const sf::FloatRect& rect) const {
    return sprite.getGlobalBounds().intersects(rect);
}
bool Player::collidesWith(const Obstacle& obstacle) const {
    auto BBs = obstacle.getBoundingBoxes();
    sf::FloatRect BB = BBs.first;
    sf::FloatRect TB = BBs.second;
    return collidesWith(BB) || collidesWith(TB);
}

bool Player::getIsAlive() const {
    return isAlive;
}
sf::Vector2f Player::getSize() const {
    return sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

void Player::setTexture(const std::string& filename) {
    if (texture.loadFromFile(filename)) {
        sprite.setTexture(texture);
    } else {
        std::cout << "Error loading player texture." << std::endl;
    }
}
void Player::sethasCollidedWithObstacle(bool boolean) {
    hasCollidedWithObstacle = boolean;
}
void Player::setPosition(sf::Vector2f vector) {
    sprite.setPosition(vector);
}
void Player::setDefaultPosition() {
    sprite.setPosition(CENTER_X - sprite.getLocalBounds().width / 2, CENTER_Y - sprite.getLocalBounds().height / 2);
}


sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

void Player::revive() {
    isAlive = true;
    canJump = true;
    hasCollidedWithObstacle = false;
    //setDefaultTexture();
    currentFrame = 0;  // Reset currentFrame
    elapsedTime = 0.0f;  // Reset elapsedTime
}
void Player::kill() {
    isAlive = false;
}
void Player::jump() {
    velocityY = jumpStrength;
}

void Player::checkIfTouchingGround() {
    //-300 is the base height
    if (sprite.getPosition().y + sprite.getLocalBounds().height >= SCREEN_HEIGHT - game->getBaseHeight()) {
        sprite.setPosition(sprite.getPosition().x, SCREEN_HEIGHT - sprite.getLocalBounds().height - game->getBaseHeight());
        kill();
        velocityY = 0.0f;  // Reset velocity when on the ground
        game->stopObstacleMovement();  // Access the Game class function
    }
}
void Player::checkIfTouchingTop() {
    float y = sprite.getPosition().y;
    if (y < 0)
        sprite.move(0, -y);
}
void Player::checkJump() {
    if (!hasCollidedWithObstacle) {
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

