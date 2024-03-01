// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(float initialX, float initialY);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    void jump();

    sf::FloatRect getBoundingBox() const;

    bool collidesWith(const sf::FloatRect& BoundingBox) const;

private:
    sf::RectangleShape shape;
    float velocityY;
    float accelerationY;

    const float jumpStrength;
    bool isJumpKeyPressed;
    bool canJump;
};

#endif // PLAYER_H
