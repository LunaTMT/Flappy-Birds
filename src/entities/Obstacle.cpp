#include "Obstacle.h"
#include "globals.h"

Obstacle::Obstacle(float x, float y)
    : bottom_tube(x, y, 50, SCREEN_HEIGHT - y, sf::Color::Blue),
      top_tube(x, 0, 50, y - 150, sf::Color::Red)
{
}

void Obstacle::draw(sf::RenderWindow& window) {
    bottom_tube.draw(window);
    top_tube.draw(window);
}
