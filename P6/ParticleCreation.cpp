#include "ParticleCreation.h"

#include <iostream>
#include <SFML/Graphics/Color.hpp>

#include "MyParticle.h"
#include "../SFML_Scripts/SFML_Particle.h"
#include "Utils.h"


ParticleCreation::ParticleCreation()
{
    std::cout << "Start Creation!!" << std::endl;
	// Starts the initialization of all particles to be created
	Creation_Initialize();
}

ParticleCreation::~ParticleCreation()
{
    std::cout << "End Creation!!" << std::endl;
}

// This is where all the particles / shapes are created
void ParticleCreation::Creation_Initialize()
{
    // Offset for the starting point of all created physics object
    Utils::offset = MyVector(0, 500);
    MyVector renderPoint;

    // Create a particle
    ParticleStruct particle_struct1 = 
    {10.0f, MyVector(100, 0),
    	MyVector(0, 10), MyVector(0, 10)};
    MyParticle* particle1 = new MyParticle(particle_struct1);
    
    ParticleStruct particle_struct2 = 
    {10.0f, MyVector(200, 0),
    	MyVector(0, 10), MyVector(0, 10)};
    MyParticle* particle2 = new MyParticle(particle_struct2);

    ParticleStruct particle_struct3 = 
    {10.0f, MyVector(300, 0),
    	MyVector(0, 10), MyVector(0, 10)};
    MyParticle* particle3 = new MyParticle(particle_struct3);

    ParticleStruct particle_struct4 = 
    {10.0f, MyVector(400, 0),
    	MyVector(0, 10), MyVector(0, 10)};
    MyParticle* particle4 = new MyParticle(particle_struct4);

    // Create an SFML particle
    SFML_ParticleStruct shape_struct1 = {
    	50.0f, sf::Color::Green, particle1, renderPoint};
    SFML_Particle* SFML_particle1 = new SFML_Particle(shape_struct1);

    SFML_ParticleStruct shape_struct2 = {
    	50.0f, sf::Color::Yellow, particle2, renderPoint};
    SFML_Particle* SFML_particle2 = new SFML_Particle(shape_struct2);
    
    SFML_ParticleStruct shape_struct3 = {
    	50.0f, sf::Color::Red, particle3, renderPoint};
    SFML_Particle* SFML_particle3 = new SFML_Particle(shape_struct3);

    SFML_ParticleStruct shape_struct4 = {
    	50.0f, sf::Color::White, particle4, renderPoint};
    SFML_Particle* SFML_particle4 = new SFML_Particle(shape_struct4);
}
