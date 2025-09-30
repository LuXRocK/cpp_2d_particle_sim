#pragma once
#include "Vector2d.hpp"
#include <cmath>
#include <SFML/Graphics.hpp>

class Particle {
    public:
        Vector2d position;
        Vector2d velocity;
        float radius;
        sf::CircleShape shape;
        sf::Color color;

        Particle(Vector2d _position, Vector2d _velocity, float _radius = 0.0f, sf::Color color = sf::Color::Green);

        void update(float dt, int windwoWidth, int windowHeight);
        void draw(sf::RenderWindow& window);
        void handleCollisionsWithWalls(int windowWidth, int windowHeight);
        float distance(const Particle& other);
        void handleCollisionWithParticles(Particle& other);
};