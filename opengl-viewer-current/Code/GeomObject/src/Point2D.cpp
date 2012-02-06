
#include <Point2D.h>
Point2D::Point2D():
Mat2x1()
{
}
Point2D::Point2D(double iX, double iY):
Mat2x1()
{
	SetAt(0, &iX);
	SetAt(1, &iY);
}
Point2D::Point2D(double *arr):
Mat2x1(arr)
{
}

double Point2D::GetX() const
{
	return GetAt(0);
}
double Point2D::GetY() const
{
	return GetAt(1);
}

Point2D::Point2D(const Point2D& iPt)
{
	double d1 = iPt.GetX();
	double d2 = iPt.GetY(); 
	SetAt(0, &d1);
	SetAt(1, &d2);
}
//Point2D& Point2D::operator=(Point2D&iPt)
//{
//	SetAt(1, iPt.GetX());
//	SetAt(2, iPt.GetY());
//}
