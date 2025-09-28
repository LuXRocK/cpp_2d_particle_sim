#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Particle.hpp"
#include "Vector2d.hpp"

class World {
    private:
        std::vector<Particle> particles;
    public:
        World();

        void addParticle(const Vector2d& position, const Vector2d& velocity, float radius, sf::Color);
        void update(float dt, int windowWidth, int windowHeight);
        void draw(sf::RenderWindow& window);
};