
#include "Vector3.h"

Vector3::Vector3():
Mat3x1()
{
}

Vector3::Vector3(double im1, double im2, double im3):
Mat3x1()
{
	SetAt(0, &im1);
	SetAt(1, &im2);
	SetAt(2, &im3);
}
void Vector3::Set(double im1, double im2, double im3)		
{
	SetAt(0, &im1);
	SetAt(1, &im2);
	SetAt(2, &im3);
}
double Vector3::GetX()
{
	return GetAt(0);
}
double Vector3::GetY()
{
	return GetAt(1);
}
double Vector3::GetZ()
{
	return GetAt(2);
}
