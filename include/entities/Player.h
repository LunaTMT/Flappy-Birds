#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <array> // Include the array header

// Forward declaration for the Game class
class Game;

// Forward declaration for the Obstacle class
class Obstacle;

class Player {
public:
    Player(Game& game);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    bool collidesWith(const sf::FloatRect& rect) const;
    bool collidesWith(const Obstacle& obstacle) const;

    bool         getIsAlive() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;


    void setTexture(const std::string& filename);
    void sethasCollidedWithObstacle(bool boolean);
    void setPosition(sf::Vector2f vector);
    void setDefaultPosition();
    //void setDefaultTexture();

    void revive();
    void kill();
    void jump();

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float velocityY;
    float accelerationY;

    const float jumpStrength;
    bool isJumpKeyPressed;
    bool canJump;
    bool isAlive;
    bool hasCollidedWithObstacle;

    // Reference to the Game class
    Game* game;

    // Animation-related members as an array
    std::array<sf::Texture, 3> animationFrames; // Adjust the size as needed
    unsigned int currentFrame;
    float frameDuration;
    float elapsedTime;

    void loadAnimationFrames();
    void updateAnimation(float deltaTime);

    void checkIfTouchingGround();
    void checkIfTouchingTop();
    void checkJump();

    

};

#endif // PLAYER_H
