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

    for(int i = 0; i < particles.size(); i++){
        for(int j = i + 1; j < particles.size(); j++){
            float dist = particles[i].distance(particles[j]);
            float maxDist = particles[i].radius + particles[j].radius;
            if(dist <= maxDist){
                Vector2d normal = particles[i].position - particles[j].position;
                normal = normal.normalized();

                particles[i].velocity = particles[i].velocity - normal * (2.0f * particles[i].velocity.dot(normal));
                particles[j].velocity = particles[j].velocity - normal * (2.0f * particles[j].velocity.dot(normal));
            }
        }
    }
}

void World::draw(sf::RenderWindow& window){
    for(Particle& particle : particles){
        particle.draw(window);
    }
};
