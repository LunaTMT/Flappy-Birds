#pragma once

#include <SFML/Graphics.hpp>

class Tube {
public:
    Tube(float x, float y, float width, float height, int type);
    void draw(sf::RenderWindow& window);
    void move(float deltaX, float deltaY);
    void flipImageVertically();

    // Getter methods
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    sf::FloatRect getBoundingBox() const;

private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Sprite sprite;  // Change to sf::Sprite
    sf::Texture texture;
};
