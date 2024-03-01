#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

// Forward declaration for the Obstacle class
class Obstacle;

class Player {
public:
    Player(float initialX, float initialY);

    bool isAlive;    

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    void jump();

    bool collidesWith(const sf::FloatRect& rect) const; 
    bool collidesWith(const Obstacle& obstacle) const;
    
    void setColour(const sf::Color& colour);    

private:
    sf::RectangleShape shape;
    float velocityY;
    float accelerationY;

    const float jumpStrength;
    bool isJumpKeyPressed;
    bool canJump;
    
};

#endif // PLAYER_H
