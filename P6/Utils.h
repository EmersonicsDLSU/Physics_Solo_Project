#ifndef UTILS
#define UTILS
#include "MyVector.h"

class Utils
{
public:
	// How much we want to offset the origin point
	static MyVector offset;
	// Should convert our Point in the engine to the
	// Appropriate SFML point for rendering
	static MyVector P6ToSFMLPoint(MyVector v);
};

#endif // !UTILS