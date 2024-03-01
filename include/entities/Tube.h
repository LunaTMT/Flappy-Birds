#pragma once

#include <SFML/Graphics.hpp>

class Tube {
public:
    Tube(float x, float y, float width, float height, sf::Color colour);
    void draw(sf::RenderWindow& window);
    void move(float deltaX, float deltaY);

    // Getter methods
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;

    sf::FloatRect getBoundingBox() const;



private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;
};
    