#include "MyParticle.h"

#include <cmath>
#include <iostream>

#include "PhysicsWorld.h"
#include "Utils.h"

MyParticle::MyParticle(ParticleStruct particleStruct) : particleStruct(particleStruct)
{
    // Add a reference to the Particle1 to our PhysicWorld(Engine)
	PhysicsWorld::getInstance()->AddParticle(this);
}

void MyParticle::Destroy()
{
	isDestroyed = true;
}

/*
// Convert the formula "P2=P1+Vt" into a function
void MyParticle::UpdatePosition(float time)
{
	// P2    =     P1        V         t
	position = position + velocity * time;
}
*/
// Convert the formula "P2 = P1 + (Vi t + (At^2) / 2)" into a function
void MyParticle::UpdatePosition(float time)
{
	// P2    =   P1     +     V     *   t    + [ (     A      *            t^2    )  *   1/2
	particleStruct.position = 
		particleStruct.position + (particleStruct.velocity * time) + 
		( (particleStruct.acceleration * powf(time, 2)) * (1.0f/2) );
}
// Convert the formula "Vf=Vi+At" into a function
void MyParticle::UpdateVelocity(float time)
{
	// Vf    =    Vi           A          t
	particleStruct.velocity =
		particleStruct.velocity + particleStruct.acceleration * time;
}
// Single function to call ALL updates for the properties of the Particle
void MyParticle::Update(float time)
{
	//std::cout << "Position " << particleStruct.position.x << ":" << particleStruct.position.y << std::endl;

	// Update the position of the particle first
	UpdatePosition(time);
	// Update the velocity next
	UpdateVelocity(time);
}
// Convert the current position in our Physics Engine to SFML point
MyVector MyParticle::ToRenderPoint()
{
	return Utils::P6ToSFMLPoint(particleStruct.position);
}
