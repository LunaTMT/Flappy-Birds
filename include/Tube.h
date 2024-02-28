#pragma once

#include <SFML/Graphics.hpp>

class Tube {
public:
    Tube(float x, float y, float width, float height, sf::Color colour);
    void draw(sf::RenderWindow& window);

private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;
};
    