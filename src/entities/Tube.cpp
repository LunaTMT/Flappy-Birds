#include "Tube.h"
#include <iostream>
#include <string>

Tube::Tube(float x, float y, float width, float height, int type)
    : position(x, y), size(width, height)
{
    sprite.setPosition(position);

    // type 0 bottom tube, type 1 top tube
    std::string file_name = !type ? "top" : "bottom";
    std::string file_path = "assets/images/" + file_name + "-pipe-green.png";

    if (texture.loadFromFile(file_path)) {
        sprite.setTexture(texture);
    } else {
        std::cout << "No tube image." << std::endl;
    }
}

void Tube::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Tube::move(float deltaX, float deltaY) {
    position.x += deltaX;
    position.y += deltaY;
    sprite.setPosition(position);
}

sf::Vector2f Tube::getPosition() const {
    return position;
}

sf::Vector2f Tube::getSize() const {
    // Get the size from the local bounds of the sprite
    return sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

sf::FloatRect Tube::getBoundingBox() const {
    return sprite.getGlobalBounds();
}
