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
