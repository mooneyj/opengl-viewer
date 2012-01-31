
#include <Point2D.h>
Point2D::Point2D():
Mat2x1()
{
}
Point2D::Point2D(double iX, double iY):
Mat2x1()
{
	SetAt(1, iX);
	SetAt(2, iY);
}
Point2D::Point2D(double *arr):
Mat2x1(arr)
{
}

double Point2D::GetX() const
{
	return GetAt(1);
}
double Point2D::GetY() const
{
	return GetAt(2);
}

Point2D::Point2D(const Point2D& iPt)
{
	SetAt(1, iPt.GetX());
	SetAt(2, iPt.GetY());
}
//Point2D& Point2D::operator=(Point2D&iPt)
//{
//	SetAt(1, iPt.GetX());
//	SetAt(2, iPt.GetY());
//}
