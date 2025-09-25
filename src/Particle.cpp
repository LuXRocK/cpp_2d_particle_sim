#include "Particle.hpp"


Particle::Particle(Vector2d _position, Vector2d _velocity, float _radius) : position(_position), velocity(_velocity), radius(_radius) {}

void Particle::update(float dt){
    Vector2d delta_pos = velocity * dt;
    position += delta_pos;
}

void Particle::draw(sf::RenderWindow& window) {
    sf::Vector2f new_position(position.x, position.y);
    sf::CircleShape particle(radius);
    particle.setPosition(new_position);
    particle.setFillColor(sf::Color::Green);
    window.draw(particle);
}