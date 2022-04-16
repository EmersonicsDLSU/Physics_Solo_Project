#ifndef MY_PARTICLE_H
#define  MY_PARTICLE_H

#include "MyVector.h"

struct ParticleStruct
{
	// Mass of this particle- Will be used later
	float mass;
	// Position of the particle in space
	MyVector position;
	// Current velocity of the particle
	MyVector velocity;
	// Current acceleration of the particle
	MyVector acceleration;
};

class MyParticle
{
public:
	MyParticle(ParticleStruct particleStruct);
	ParticleStruct particleStruct;
protected:
	// Flag to hold when to destroy this Particle
	bool isDestroyed = false;
public:
	// Getter property for the isDestroy field / variable
	bool IsDestroyed(){ return isDestroyed;}
	// Will set our flag
	void Destroy();
protected:
	// Updates the position of this particle relative to time
	void UpdatePosition(float time);
	// Updates the velocity of this particle relative to time
	void UpdateVelocity(float time);

public:
	// Updates the needed particle properties relative to time
	void Update(float time);
	// Convert the current position in our Physics Engine to SFML point
	MyVector ToRenderPoint();
};

#endif // MY_PARTICLE_H

