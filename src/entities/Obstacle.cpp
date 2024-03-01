// Obstacle.cpp
#include "Obstacle.h"
#include "Tube.h"

Obstacle::Obstacle(float x, float y)
    : bottom_tube(std::make_shared<Tube>(x, y, TUBE_WIDTH, SCREEN_HEIGHT - y, sf::Color::Blue)),
      top_tube   (std::make_shared<Tube>(x, 0, TUBE_WIDTH, y - 150,           sf::Color::Red)),
      velocityX(-100.0f) {}

void Obstacle::update(float deltaTime) {
    bottom_tube->move(velocityX * deltaTime, 0);
    top_tube->move(velocityX * deltaTime, 0);
}

void Obstacle::draw(sf::RenderWindow& window) {
    bottom_tube->draw(window);
    top_tube->draw(window);
}

bool Obstacle::isOutOfBounds() const {
    return bottom_tube->getPosition().x + bottom_tube->getSize().x < 0;
}


std::pair<sf::FloatRect, sf::FloatRect> Obstacle::getBoundingBoxes() const {
    return std::make_pair(bottom_tube->getBoundingBox(), top_tube->getBoundingBox());
}
