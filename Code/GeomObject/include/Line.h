#ifndef _Line_h
#define _Line_h

#include <Object.h>
#include <Point3D.h>
#include <FixedSizeMatrix.h>
#define Line FixedSizeMatrix<Point3D, 2>

class LineR : public Object
{
public:
	LineR(Point3D *ipPts, Mat3x1 &iColorMatrix);
	LineR(Point3D *ipPt1, Point3D *ipPt2, Mat3x1 &iColorMatrix);
	virtual void Draw();
private:
	Line _ln;
};


#endif