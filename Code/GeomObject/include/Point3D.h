
#ifndef _Point2D_h
#define _Point2D_h
#include <Mat3x1.h>

class Point3D : public Mat3x1
{
public:
	Point3D(double iX, double iY, double iZ);
	Point3D();
	Point3D(double *arr);
	void Set(double *arr);
	double GetX() const;
	double GetY() const;
	double GetZ() const;

	Point3D(const Point3D& iPt);
	~Point3D();
};

#endif

