#include "Tube.h"

Tube::Tube(float x, float y, float width, float height, sf::Color colour)
    : position(x, y), size(width, height)
{
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(colour);
}

void Tube::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Tube::move(float deltaX, float deltaY) {
    position.x += deltaX;
    position.y += deltaY;
    shape.setPosition(position);
}

sf::Vector2f Tube::getPosition() const {
    return position;
}

sf::Vector2f Tube::getSize() const {
    return size;
}