#ifndef SFML_PARTICLE_H
#define SFML_PARTICLE_H
#include <SFML/Graphics/CircleShape.hpp>
#include "../P6/MyVector.h"
#include "../P6/MyParticle.h"

#include <iostream>
#include <tuple>

struct SFML_ParticleStruct
{
	float radius;
    sf::Color color;
    MyParticle* particle; 
    MyVector& renderPoint;
    sf::CircleShape shape;
};

class SFML_Particle
{
public:
    SFML_Particle(SFML_ParticleStruct &particleStruct);
    SFML_ParticleStruct particleStruct;
};

#endif // SFML_PARTICLE_H


