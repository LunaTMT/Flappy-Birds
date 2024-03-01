#pragma once

#include <SFML/Graphics.hpp>

#include "Tube.h"

class Obstacle {
public:
    Obstacle(float x, float y);
    void draw(sf::RenderWindow& window);

private:
    Tube bottom_tube;
    Tube top_tube;
};
