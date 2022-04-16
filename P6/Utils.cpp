#include "Utils.h"

// Initialize the offset to 0
MyVector Utils::offset = MyVector();

// Simply use vector Addition to "move our origin"
MyVector Utils::P6ToSFMLPoint(MyVector v)
{
	MyVector ret = MyVector(v.x, -v.y);
	return ret + offset;
}