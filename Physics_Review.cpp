#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>

#include "P6/ParticleCreation.h"
#include "P6/MyParticle.h"
#include "P6/MyVector.h"
#include "P6/PhysicsWorld.h"
#include "P6/Utils.h"
#include "SFML_Scripts/SFML_Particle.h"
#include "SFML_Scripts/SFML_ParticleWorld.h"
#include "SFML_Scripts/SFML_Class.h"

using namespace std::chrono_literals;
using namespace std::chrono;
// higher ms = bigger time step; lower ms = lower time step(accurate)
//16ms = 1 frame in a 60fps
constexpr nanoseconds timestep(16ms);

int main() {
    // calls the class constructor to create all particles / shape objects
    ParticleCreation FirstCreation = ParticleCreation();

	using clock = high_resolution_clock;
    auto curr_time = clock::now();
    auto prev_time = curr_time;
    nanoseconds curr_ns(0ns);
    sf::Event event;
    bool isPlaying = true;
    while (isPlaying) {
        curr_time = clock::now();
        auto dur = duration_cast<nanoseconds> (curr_time - prev_time);
        prev_time = curr_time;

        curr_ns += dur;
        if (curr_ns >= timestep) {
            auto ms = duration_cast<milliseconds>(curr_ns);
            // Call the update when it reaches a certain time-step
            // ms is in milisecs while engine is using secs so we divide by 1000
            
            PhysicsWorld::getInstance()->Update((float)ms.count() / 1000);
            // Update the position of our shape in SFML
			SFML_ParticleWorld::getInstance()->Update();

            curr_ns -= timestep;
            //window.
            SFML_Class::getInstance()->window->pollEvent(event);
            if (event.type == sf::Event::Closed)
            {
	            isPlaying = false;
                SFML_Class::getInstance()->window->close();
            }
            SFML_Class::getInstance()->window->clear();
			SFML_ParticleWorld::getInstance()->DrawUpdate();
            SFML_Class::getInstance()->window->display();
        }
    }
    PhysicsWorld::getInstance()->PhysicsWorld_Destructor();
    SFML_ParticleWorld::getInstance()->SFML_ParticleWorld_Destructor();
    return 0;
}