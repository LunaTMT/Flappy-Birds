// Obstacle.h
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Tube.h"
#include "globals.h"
#include <memory>

class Obstacle {
public:
    Obstacle(float x, float y);
    // No need for a custom destructor

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void stopMoving();

    bool beenPassed;
    bool isOutOfBounds() const;
    
    
    std::pair<sf::FloatRect, sf::FloatRect> getBoundingBoxes() const;
    sf::Vector2f getPosition() const;



private:
    std::shared_ptr<Tube> top_tube;
    std::shared_ptr<Tube> bottom_tube;
    
    float velocityX;
    bool isMoving;
    
};

#endif // OBSTACLE_H
