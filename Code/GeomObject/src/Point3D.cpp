
#include <Point3D.h>
Point3D::Point3D():
Mat3x1()
{
}
Point3D::Point3D(double iX, double iY, double iZ):
Mat3x1()
{
	SetAt(0, &iX);
	SetAt(1, &iY);
	SetAt(2, &iZ);
}
Point3D::Point3D(double *arr):
Mat3x1(arr)
{
}
Point3D::~Point3D()
{
}

void Point3D::Set(double *arr)
{
	SetAt(0, &arr[0]);
	SetAt(1, &arr[1]);
	SetAt(2, &arr[2]);
}

double Point3D::GetX() const
{
	return GetAt(0);
}
double Point3D::GetY() const
{
	return GetAt(1);
}
double Point3D::GetZ() const
{
	return GetAt(2);
}

Point3D::Point3D(const Point3D& iPt)
{
	double d1 = iPt.GetX();
	double d2 = iPt.GetY();
	double d3 = iPt.GetZ();

	SetAt(0, &d1);
	SetAt(1, &d2);
	SetAt(2, &d3);
}

