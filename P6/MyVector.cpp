#include "MyVector.h"

#include <cmath>

//gets the direction; normalize this object
void MyVector::Normalize()
{
	float n = GetMagnitude();
	if (n > 0) {
		(*this) *= ((1.0f) / n);
	}
}
// gets the length of this vector
float MyVector::GetMagnitude()
{
	return sqrt(SquareMagnitude());
}
// Square Magnitude (Pythagorean Theorem)
float MyVector::SquareMagnitude()
{
	return (x * x) + (y *y);
}
// gets the length of this vector (Two vectors Presented)
float MyVector::GetMagnitude(MyVector b)
{
	return sqrt(powf(x - b.x, 2) + powf(this->y - b.y, 2));
}
// gets the normalize vector
MyVector MyVector::getDirection(float magnitude)
{
	MyVector direction(x, y);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	return direction;
}
// gets the vector component product
MyVector MyVector::ComponentProduct(const MyVector v)
{
	return MyVector(x * v.x, y * v.y);
}
// gets the scalar / dot product (two vector parameters)
float MyVector::getScalarProduct(MyVector vec1, MyVector vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}
// Invert the component axis of vector
void MyVector::Invert()
{
	x = -x;
	y = -y;
}
// Vector Addition
void MyVector::operator+=(const MyVector v)
{
	x += v.x;
	y += v.y;
}
MyVector MyVector::operator+(const MyVector v)
{
	return MyVector(x + v.x, y + v.y);
}
// Vector Subtraction
void MyVector::operator-=(const MyVector v)
{
	x -= v.x;
	y -= v.y;
}
MyVector MyVector::operator-(const MyVector v)
{
	return MyVector(x - v.x, y - v.y);
}
// Vector Multiplication
void MyVector::operator*=(const float f)
{
	x *= f;
	y *= f;
}
MyVector MyVector::operator*(const float f)
{
	return MyVector(x * f, y * f);
}
// Vector Dot Product
float MyVector::operator*(const MyVector v)
{
	return (x * v.x) + (y * v.y);
}
