#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2d.hpp"

int main()
{

    Vector2d a;
    Vector2d b(1, 3);
    std::cout << a.x << std::endl;
    std::cout << b.x << std::endl;

    sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
