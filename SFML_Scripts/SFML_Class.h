#ifndef SFML_CLASS_H
#define SFML_CLASS_H

#include <SFML/Graphics/RenderWindow.hpp>

class SFML_Class
{
public:
	static SFML_Class *sharedInstance;
	sf::RenderWindow *window;

	static SFML_Class* getInstance();
private:
	SFML_Class();
	~SFML_Class();
};

#endif // SFML_CLASS_H