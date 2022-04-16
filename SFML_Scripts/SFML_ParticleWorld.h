#ifndef SFML_PARTICLE_WORLD_H
#define SFML_PARTICLE_WORLD_H

#include <list>
#include "SFML_Particle.h"



class SFML_ParticleWorld
{
public:
	static SFML_ParticleWorld* getInstance();

	void Update();
	void DrawUpdate();
	std::list<SFML_Particle*> SFML_ParticleList;
	// Function to add particle in the holder
	void AddParticle(SFML_Particle *toAdd);
	// Manual Destructor
	void SFML_ParticleWorld_Destructor();
	
private:
	// Constructor
	SFML_ParticleWorld();
	// Destructor
	~SFML_ParticleWorld();
	static SFML_ParticleWorld* sharedInstance;
};

#endif // SFML_PARTICLE_WORLD_H

