#include <Line.h>
#include <Point3D.h>
#include <glut.h>

void LineR::Draw()
{
	glBegin(GL_LINES);
		glColor3f(GetColor().GetAt(1), GetColor().GetAt(2), GetColor().GetAt(3));
		glVertex3f(_ln.GetAt(1).GetX(), _ln.GetAt(1).GetY(), _ln.GetAt(1).GetZ());
		glVertex3f(_ln.GetAt(2).GetX(), _ln.GetAt(2).GetY(), _ln.GetAt(2).GetZ());
	glEnd();
}
LineR::LineR(Point3D *ipPts, Mat3x1 &iColorMatrix):
Object(iColorMatrix),_ln(ipPts)
{
}
LineR::LineR(Point3D *ipPt1, Point3D *ipPt2, Mat3x1 &iColorMatrix):
Object(iColorMatrix)
{
	_ln.SetAt(1, *ipPt1);
	_ln.SetAt(2, *ipPt2);
}
