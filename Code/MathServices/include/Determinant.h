// This code belongs to Vinayak Kane

#ifndef _Determinant_h
#define _Determinant_h

#include <BasicSolve.h>

class Determinant : public BasicSolve
{
public:
	Determinant();
	virtual ~Determinant()=0{};
protected:
};
class Determinant3x3 : public Determinant
{
public:
	Determinant3x3();
	Determinant3x3(double im[3][3]);
	virtual void Solve();
	void SetRow(Count iCount, double im[]);
	void SetColumn(Count iCount, double im[]);
	double operator+(Determinant3x3&iD);
	double operator/(Determinant3x3&iD);
private:
	double _m[3][3];
};

static double ComputeDeterminant3x3(double iA[][3])
{
	//double m11=0., m12=0.,m13=0.,m21=0.,m22=0.,m23=0.,m31=0.,m32=0.,m33=0.;
	double t1 = iA[0][0] * (iA[1][1] * iA[2][2] - iA[2][1] * iA[1][2]);
	double t2 = iA[0][1] * (iA[1][0] * iA[2][2] - iA[1][2] * iA[2][0]);
	double t3 = iA[0][2] * (iA[1][0] * iA[2][1] - iA[2][0] * iA[1][1]);

	return (t1-t2+t3);
}

#endif
