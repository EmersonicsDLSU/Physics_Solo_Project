#include "SFML_Particle.h"

#include "SFML_ParticleWorld.h"

SFML_Particle::SFML_Particle(SFML_ParticleStruct &particleStruct) : particleStruct(particleStruct)
{
    // Create a circle to represent the particle
    sf::CircleShape shape(particleStruct.radius);
    shape.setFillColor(particleStruct.color);
    // Set the origin at the center
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    // Store our render point to avoid recomputing it every time
	particleStruct.renderPoint = particleStruct.particle->ToRenderPoint();
	// Set the position to be the same as the particle
    shape.setPosition(particleStruct.renderPoint.x, particleStruct.renderPoint.y);

    // Assigns the shape
    this->particleStruct.shape = shape;
    SFML_ParticleWorld::getInstance()->AddParticle(this);
}
