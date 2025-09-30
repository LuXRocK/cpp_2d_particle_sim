#include "Particle.hpp"


Particle::Particle(Vector2d _position, Vector2d _velocity, float _radius, sf::Color _color) : position(_position), velocity(_velocity), radius(_radius), shape(_radius), color(_color) {
    sf::Vector2f origin_pos(_radius, _radius);
    shape.setOrigin(origin_pos);
    shape.setFillColor(color);
}

void Particle::update(float dt, int windowWidth, int windowHeight){
    Vector2d delta_pos = velocity * dt;
    position += delta_pos;
    handleCollisionsWithWalls(windowWidth, windowHeight);
    sf::Vector2f new_position(position.x, position.y);
    shape.setPosition(new_position);
}

void Particle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Particle::handleCollisionsWithWalls(int windowWidth, int windowHeight) {
    if(position.x + radius >= windowWidth) {
        position.x = windowWidth - radius;
        velocity.x = velocity.x * -1;
    };
    if(position.x - radius <= 0) {
        position.x = 0 + radius;
        velocity.x = velocity.x * -1;
    };
    if(position.y + radius >= windowHeight) {
        position.y = windowHeight - radius;    
        velocity.y = velocity.y * -1;
    };
    if(position.y - radius <= 0) {
        position.y = 0 + radius;
        velocity.y = velocity.y * -1;
    };
}

float Particle::distance(const Particle& other){
    return Vector2d(position.x - other.position.x, position.y - other.position.y).length();
}

void Particle::handleCollisionWithParticles(Particle& other){
    float dist = distance(other);
    float maxDist = radius + other.radius;
    if(dist <= maxDist && dist > 0.0f){
        Vector2d normal = position - other.position;
        normal = normal.normalized();

        velocity = velocity - normal * (2.0f * velocity.dot(normal));
        other.velocity = other.velocity - normal * (2.0f * other.velocity.dot(normal));

        float overlap = maxDist - dist;
        position = position + normal * (overlap / 2.0f);
        other.position = other.position - normal * (overlap / 2.0f);
    }
}
