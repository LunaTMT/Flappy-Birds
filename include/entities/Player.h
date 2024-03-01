#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

// Forward declaration for the Obstacle class
class Obstacle;

class Player {
public:
    Player(float initialX, float initialY);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    
    bool collidesWith(const sf::FloatRect& rect) const; 
    bool collidesWith(const Obstacle& obstacle) const;
    
    void checkIfTouchingGround();
    void checkIfTouchingTop();
    void checkJump();
    
    bool getIsAlive() const;
    
    void setColour(const sf::Color& colour);    
    
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
    
};

#endif // PLAYER_H
