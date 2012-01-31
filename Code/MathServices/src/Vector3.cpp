
#include "Vector3.h"

Vector3::Vector3():
Mat3x1()
{
}

Vector3::Vector3(double im1, double im2, double im3):
Mat3x1()
{
	SetAt(1, im1);
	SetAt(2, im2);
	SetAt(3, im3);
}
void Vector3::Set(double im1, double im2, double im3)		
{
	SetAt(1, im1);
	SetAt(2, im2);
	SetAt(3, im3);
}
double Vector3::GetX()
{
	return GetAt(1);
}
double Vector3::GetY()
{
	return GetAt(2);
}
double Vector3::GetZ()
{
	return GetAt(3);
}
