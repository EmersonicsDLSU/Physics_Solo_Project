#include "SFML_Class.h"

SFML_Class* SFML_Class::sharedInstance = nullptr;

SFML_Class* SFML_Class::getInstance()
{
	//initialize
	if(sharedInstance == nullptr)
	{
		sharedInstance = new SFML_Class();
	}
	return sharedInstance;
}

SFML_Class::SFML_Class()
{
	window = new sf::RenderWindow(sf::VideoMode(500, 500), "P6 Test");
}


SFML_Class::~SFML_Class()
{
	if(sharedInstance != nullptr)
	{
		delete sharedInstance;
	}
	if(sharedInstance != nullptr)
	{
		delete window;
	}
}
