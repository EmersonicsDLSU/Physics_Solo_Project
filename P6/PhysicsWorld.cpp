#include "PhysicsWorld.h"

#include <iostream>

PhysicsWorld* PhysicsWorld::sharedInstance = nullptr;

PhysicsWorld* PhysicsWorld::getInstance()
{
	//initialize
	if(sharedInstance == nullptr)
	{
		sharedInstance = new PhysicsWorld();
	}
	return sharedInstance;
}
// Constructor definition
PhysicsWorld::PhysicsWorld()
{
}
// Destructor definition
PhysicsWorld::~PhysicsWorld()
{
}
// Adds a particle to the list
void PhysicsWorld::AddParticle(MyParticle* toAdd)
{
	// Add a particle to the back(last element) of the list
	particles.push_back(toAdd);
}
// Updates each of our particle in the world
void PhysicsWorld::Update(float time)
{
	// Update the list first before calling
	// The updates for the particles
	UpdateParticleList();

	// Create an iterator and start at the beginning of the list
	for (std::list<MyParticle*>::iterator p = particles.begin();
		p != particles.end(); p++)
	{
		// Call the particle's update
		(*p)->Update(time);
	}
}
// Manual Destructor
void PhysicsWorld::PhysicsWorld_Destructor()
{
	for (std::list<MyParticle*>::iterator p = particles.begin();
		p != particles.end(); p++)
	{
		std::cout << "Delete MyParticle!!" << std::endl;
		// delete the memory alloc for "MyParticle" obj
		delete *p;
		*p = nullptr;
	}
}
// Checks if the particle is destroyed, if so, we removed it from the list
void PhysicsWorld::UpdateParticleList()
{
	// Removes ALL Particles in the list that
	// returns true to the function below
	particles.remove_if(
	// Checks ALL the particles in this list
	// If their isDestroyed flag is true
		[](MyParticle *p)
		{
			return p->IsDestroyed();
		}
	);
}
