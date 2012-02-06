#ifndef _Line_h
#define _Line_h

#include <Object.h>
#include <Point3D.h>
#include <FixedSizeArray.h>
#define Line FixedSizeArray<Point3D, 2>

class LineR : public Object
{
public:
	~LineR();
	LineR(Point3D *ipPts, Mat3x1 &iColorMatrix);
	LineR(Point3D *ipPt1, Point3D *ipPt2, Mat3x1 &iColorMatrix);
	virtual void Draw();
	virtual void Set(Point3D *ipPt1, Point3D *ipPt2);
	virtual Point3D *GetPt1() const;
	virtual Point3D *GetPt2() const;
	virtual void Translate(Vector3 &iDir, double idist);
	LineR& operator=(const LineR& iLine);
private:
	Line					*_ln;
};


#endif