
#include <Point3D.h>
Point3D::Point3D():
Mat3x1()
{
}
Point3D::Point3D(double iX, double iY, double iZ):
Mat3x1()
{
	SetAt(1, iX);
	SetAt(2, iY);
	SetAt(3, iZ);
}
Point3D::Point3D(double *arr):
Mat3x1(arr)
{
}

double Point3D::GetX() const
{
	return GetAt(1);
}
double Point3D::GetY() const
{
	return GetAt(2);
}
double Point3D::GetZ() const
{
	return GetAt(3);
}

Point3D::Point3D(const Point3D& iPt)
{
	SetAt(1, iPt.GetX());
	SetAt(2, iPt.GetY());
	SetAt(3, iPt.GetZ());
}

