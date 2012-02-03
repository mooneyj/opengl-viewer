#ifndef _Triangle_h
#define _Triangle_h
#include <Object.h>
#include <vector>
#include <BasicDefs.h>
#include <FixedSizeMatrix.h>
#include <Point3D.h>
#define Triangle FixedSizeMatrix<Point3D, 3>
/**/
class TriangleR : public Object
{
public:
	virtual ~TriangleR();
	TriangleR(Point3D *ipPts, Mat3x1 &iColorMatrix);
	TriangleR(Point3D *ipPt1, Point3D *ipPt2, Point3D *ipPt3, Mat3x1 &iColorMatrix);
	void SetTriangle(Triangle &iTr);
	void Set(Point3D *ipPts);
	Triangle GetTriangle() const;
	virtual void Draw();
	TriangleR(const TriangleR &iTr);
private:
	Triangle					*_tr;
};
/**/
#endif
