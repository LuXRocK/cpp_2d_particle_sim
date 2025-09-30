#include "World.hpp"

World::World(int windowWidth, int windowHeight) {
    float outerSize = windowWidth - (windowWidth / 5);
    float innerSize = outerSize - 10.0f;
    float centerX = windowWidth / 2;
    float centerY = windowHeight / 2;

    outer.setSize(sf::Vector2f(outerSize, outerSize));
    outer.setFillColor(sf::Color::Yellow);
    outer.setOrigin(sf::Vector2f(outerSize / 2, outerSize / 2));
    outer.setPosition(sf::Vector2f(centerX, centerY));

    inner.setSize(sf::Vector2f(innerSize, innerSize));
    inner.setFillColor(sf::Color::Black);
    inner.setOrigin(sf::Vector2f(innerSize / 2, innerSize / 2));
    inner.setPosition(sf::Vector2f(centerX, centerY));
};

void World::addParticle(const Vector2d &position, const Vector2d &velocity, float radius, sf::Color color)
{
    Particle new_particle(position, velocity, radius, color);
    particles.push_back(new_particle);
};

void World::update(float dt, int windowWidth, int windowHeight)
{
    for (Particle &particle : particles)
    {
        particle.update(dt, windowWidth, windowHeight);
    }

    for (int i = 0; i < particles.size(); i++)
    {
        for (int j = i + 1; j < particles.size(); j++)
        {
            particles[i].handleCollisionWithParticles(particles[j]);
        }
    }
}

void World::draw(sf::RenderWindow &window)
{
    window.draw(outer);
    window.draw(inner);

    for (Particle &particle : particles)
    {
        particle.draw(window);
    }
};
