#pragma once
#include "Vector2d.hpp"
#include <cmath>
#include <SFML/Graphics.hpp>

class Particle {
    public:
        Vector2d position;
        Vector2d velocity;
        float radius;

        Particle(Vector2d _position, Vector2d _velocity, float _radius = 0.0f);

        void update(float dt);
        void draw(sf::RenderWindow& window);
};