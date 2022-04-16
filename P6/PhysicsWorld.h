#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <list>

#include  "MyParticle.h"

class SFML_ParticleWorld;

class PhysicsWorld
{
public:
	static PhysicsWorld* getInstance();
	// a list of all our particles
	std::list<MyParticle*> particles;

	// Function to add particle in the holder
	void AddParticle(MyParticle *toAdd);
	// Universal Update function to call the updates of ALL particles
	void Update(float time);
	// Manual Destructor
	void PhysicsWorld_Destructor();

private:
	// Function that will check the list for
	// any particles that are needed to be removed
	// from the simulation
	void UpdateParticleList();

private:
	// Constructor
	PhysicsWorld();
	// Destructor
	~PhysicsWorld();
	static PhysicsWorld* sharedInstance;
};

#endif // PHYSICS_WORLD_H

