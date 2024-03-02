#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

// Forward declaration for the Game class
class Game;

// Forward declaration for the Obstacle class
class Obstacle;

class Player {
public:

    // Updated constructor with a reference to the Game class
    Player(float initialX, float initialY, Game& game);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    bool collidesWith(const sf::FloatRect& rect) const;
    bool collidesWith(const Obstacle& obstacle) const;

    void checkIfTouchingGround();
    void checkIfTouchingTop();
    void checkJump();

    bool getIsAlive() const; 
    sf::Vector2f getSize() const;


    void setColour(const sf::Color& colour);
    void sethasCollidedWithObstacle(bool boolean);

    void kill();
    void jump();

private:
    sf::RectangleShape shape;
    float velocityY;
    float accelerationY;

    const float jumpStrength;
    bool isJumpKeyPressed;
    bool canJump;
    bool isAlive;
    bool hasCollidedWithObstacle;

    // Reference to the Game class
    Game* game;
};

#endif // PLAYER_H
