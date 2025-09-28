#include "World.hpp"

World::World() {};

void World::addParticle(const Vector2d& position, const Vector2d& velocity, float radius, sf::Color color) {
    Particle new_particle(position, velocity, radius, color);
    particles.push_back(new_particle);
};

void World::update(float dt, int windowWidth, int windowHeight){
    for(Particle& particle : particles){
        particle.update(dt, windowWidth, windowHeight);
    }
}

void World::draw(sf::RenderWindow& window){
    for(Particle& particle : particles){
        particle.draw(window);
    }
};
