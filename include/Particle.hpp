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

        Particle(Vector2d _position, Vector2d _velocity, float _radius = 0.0f);

        void update(float dt, int windwoWidth, int windowHeight);
        void draw(sf::RenderWindow& window);
        void handleCollisionsWithWalls(int windowWidth, int windowHeight);
};