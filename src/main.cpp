#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2d.hpp"
#include "Particle.hpp"

int main()
{

    Vector2d a(100, 100);
    Vector2d b(1, 0);
    float radius = 10.0f;

    Particle particle1(a, b, radius);
    particle1.position.print();

    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        particle1.draw(window);
        particle1.update(.25f);
        particle1.position.print();
        window.display();
    }
}
