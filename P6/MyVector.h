#ifndef MY_VECTOR_H
#define MY_VECTOR_H
class MyVector
{
public:
	// Our Vector2
	float x, y;
public:
	MyVector(const float _x = 0, const float _y = 0) : x(_x), y(_y){}

	void Invert();
	// get magnitude (Pythagorean Theorem)
	float GetMagnitude();
	float SquareMagnitude();
	// get magnitude (two vectors)
	float GetMagnitude(MyVector b);
	// get the normalize vector
	MyVector getDirection(float magnitude);
	// set this vector object to be the normalize vector
	void Normalize();

	// gets the vector component product
	MyVector ComponentProduct(const MyVector v);
	// gets the scalar / dot product (two vector parameters)
	float getScalarProduct(MyVector vec1, MyVector vec2);

	// Vector Addition
	void operator+=(const MyVector v);
	MyVector operator+(const MyVector v);
	// Vector Subtraction
	void operator-=(const MyVector v);
	MyVector operator-(const MyVector v);
	// Vector Multiplication
	void operator*=(const float f);
	MyVector operator*(const float f);
	// Vector Scalar / Dot Product (operator overload)
	float operator*(const MyVector v);
};

#endif //MY_VECTOR_H
