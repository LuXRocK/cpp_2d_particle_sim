#include <SFML/Graphics.hpp>
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "Vector2d.hpp"
#include "Particle.hpp"
#include "World.hpp"

int main(int argc, char* argv[])
{

    float dt;
    int particles_amnt;

    if(argc < 1    ) {
        dt = 0.5f;
        particles_amnt = 10;
        std::cout << "Missing parameters for dt and amount of particles. Setting default valuest to 0.5 and 10" << std::endl;
    }else {
        dt = std::stof(argv[1]);
        particles_amnt = std::stoi(argv[2]);
        std::cout << "Setting dt to " << dt << " and particles amount to " << particles_amnt << "." << std::endl;
    }


    srand(static_cast<unsigned>(time(nullptr)));

    World  world;

    std::vector<sf::Color> colors {sf::Color::Green, sf::Color::Blue, sf::Color::Red};

    for(int i = 0; i < particles_amnt; i++){
        world.addParticle(Vector2d(rand() % 1001, rand() % 1001),
                    Vector2d(rand() % 21 - 10, rand() % 21 - 10),
                    rand() % 21 + 5, colors[rand() % 3]);
    }
    
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        world.update(dt, window.getSize().x, window.getSize().y);
        world.draw(window);
        window.display();
    }
}
