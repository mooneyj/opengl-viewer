
#ifndef _Point2D_h
#define _Point2D_h
#include <Mat3x1.h>
#include <Object.h>
class Point3D : public Object
{
public:
	Point3D(double iX, double iY, double iZ);
	Point3D();
	Point3D(double *arr);
	void Set(double *arr);
	void Set(double idX, double idY, double idZ);
	double GetX() const;
	double GetY() const;
	double GetZ() const;
	virtual void Draw();
	Point3D(const Point3D& iPt);
	virtual void Translate(Vector3 &iDir, double idist);
	virtual Point3D& operator=(const Point3D& ipt);
	~Point3D();
private:
	Mat3x1					*_pMatrix;
};

#endif

