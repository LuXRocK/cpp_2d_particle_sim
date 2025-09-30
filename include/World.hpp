#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Particle.hpp"
#include "Vector2d.hpp"

class World {
    private:
        std::vector<Particle> particles;
        sf::RectangleShape inner;
        sf::RectangleShape outer;
    public:
        World(int windowWidth, int windowHeight);

        void addParticle(const Vector2d& position, const Vector2d& velocity, float radius, sf::Color);
        void update(float dt, int windowWidth, int windowHeight);
        void draw(sf::RenderWindow& window);
};