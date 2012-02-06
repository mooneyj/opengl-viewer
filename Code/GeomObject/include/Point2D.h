
#ifndef _Point2D_h
#define _Point2D_h
#include <Mat2x1.h>

class Point2D : public Mat2x1
{
public:
	Point2D(double iX, double iY);
	Point2D();
	Point2D(double *arr);
	~Point2D(){};
	double GetX() const;
	double GetY() const;

	Point2D(const Point2D& iPt);
	//Point2D& operator=(Point2D&iPt);
};

#endif

