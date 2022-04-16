#include "SFML_ParticleWorld.h"
#include "SFML_Class.h"

#include <iostream>
SFML_ParticleWorld* SFML_ParticleWorld::sharedInstance = nullptr;

SFML_ParticleWorld* SFML_ParticleWorld::getInstance()
{
	//initialize
	if(sharedInstance == nullptr)
	{
		sharedInstance = new SFML_ParticleWorld();
	}
	return sharedInstance;
}
// Adds the SFML shape particle to our list
void SFML_ParticleWorld::AddParticle(SFML_Particle* toAdd)
{
	SFML_ParticleList.push_back(toAdd);
}
// Constructor definition
SFML_ParticleWorld::SFML_ParticleWorld()
{
}
// Destructor definition
SFML_ParticleWorld::~SFML_ParticleWorld()
{
}
// Manual Destructor
void SFML_ParticleWorld::SFML_ParticleWorld_Destructor()
{
	for (std::list<SFML_Particle*>::iterator p = SFML_ParticleList.begin();
		p != SFML_ParticleList.end(); p++)
	{
		std::cout << "Delete SFML_Particle!!" << std::endl;
		// delete the memory alloc for "SFML_Particle" obj
		delete *p;
		*p = nullptr;
	}
}
// Updates ALL the particle position via SFML
void SFML_ParticleWorld::Update()
{
	for (std::list<SFML_Particle*>::iterator p = SFML_ParticleList.begin();
		p != SFML_ParticleList.end(); p++)
	{
		(*p)->particleStruct.renderPoint = (*p)->particleStruct.particle->ToRenderPoint();
		(*p)->particleStruct.shape.setPosition(
			(*p)->particleStruct.renderPoint.x, (*p)->particleStruct.renderPoint.y);
	}
}
// Draws all the SFML shape to our window
void SFML_ParticleWorld::DrawUpdate()
{
	// Renders the particle that is not destroyed
	for (std::list<SFML_Particle*>::iterator p = SFML_ParticleList.begin();
		p != SFML_ParticleList.end(); p++)
	{
		if (!(*p)->particleStruct.particle->IsDestroyed())
		{
			SFML_Class::getInstance()->window->draw((*p)->particleStruct.shape);
		}
	}
}
