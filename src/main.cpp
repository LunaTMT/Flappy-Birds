#include "EmptyClass.h"
#include "Tube.h"

#include <iostream>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tube Example");

    EmptyClass emptyObject;
    Tube Obstacle1(100.0f, 450.0f, 50.0f, 50.0f, sf::Color::Blue);
    cout << "import successful";

    cout << "import successful";

    cout << "import successful";

    cout << "import successful";
    Obstacle1.draw(window);
    return 0;
}


