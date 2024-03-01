#include "EmptyClass.h"
#include "Tube.h"
#include "Obstacle.h"

#include <iostream>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tube Example");

    // Create an instance of the derived class
    Obstacle Obstacle1(100.0f, 450.0f);
    Obstacle Obstacle2(200.0f, 460.0f);
    Obstacle Obstacle3(300.0f, 470.0f);
    Obstacle Obstacle4(400.0f, 480.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Draw the tube (which is also an obstacle)
        Obstacle1.draw(window);
        Obstacle2.draw(window);
        Obstacle3.draw(window);
        Obstacle4.draw(window);

        window.display();
    }

    return 0;
}



