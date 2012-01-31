
#ifndef _Vector3_h
#define _Vector3_h

#include <Mat3x1.h>
#include <BasicDefs.h>
class Vector3 : public Mat3x1
{
public:
	Vector3();
	~Vector3(){};
	Vector3(double im1, double im2, double im3);
	void Set(double im1, double im2, double im3);
	double GetX();
	double GetY();
	double GetZ();
};

#endif
