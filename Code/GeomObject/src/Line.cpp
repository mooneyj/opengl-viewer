#include <Line.h>
#include <Point3D.h>
#include <glut.h>

void LineR::Draw()
{
	glBegin(GL_LINES);
		glColor3f(GetColor()->GetAt(0), GetColor()->GetAt(1), GetColor()->GetAt(2));
		glVertex3f(_ln->GetAt(0).GetX(), _ln->GetAt(0).GetY(), _ln->GetAt(0).GetZ());
		glVertex3f(_ln->GetAt(1).GetX(), _ln->GetAt(1).GetY(), _ln->GetAt(1).GetZ());
	glEnd();
}
LineR::LineR(Point3D *ipPts, Mat3x1 &iColorMatrix):
Object(&iColorMatrix),
_ln(new Line(ipPts))
{
}
LineR::LineR(Point3D *ipPt1, Point3D *ipPt2, Mat3x1 &iColorMatrix):
Object(&iColorMatrix),
_ln(new Line())
{
	if(_ln)
	{
		_ln->SetAt(0, ipPt1);
		_ln->SetAt(1, ipPt2);
	}
}

void LineR::Translate(Vector3 &iDir, double idist)
{
	if(_ln)
	{
		int nMaxSize = _ln->GetMaxSize();
		for(int i = 0; i < nMaxSize; i++)
		{
			_ln->GetAt(i).Translate(iDir,idist);
		}
	}
}
LineR::~LineR()
{
	delete _ln;
}

Point3D *LineR::GetPt1() const
{
	Point3D * pRetPt = 0;
	if(_ln)
		pRetPt = &(_ln->GetAt(0));
	return pRetPt;
}
Point3D *LineR::GetPt2() const
{
	Point3D * pRetPt = 0;
	if(_ln)
		pRetPt = &(_ln->GetAt(1));
	return pRetPt;
}
void LineR::Set(Point3D *ipPt1, Point3D *ipPt2)
{
	if(_ln)
	{
		_ln->SetAt(0, ipPt1);
		_ln->SetAt(1, ipPt2);
	}
}
LineR& LineR::operator=(const LineR& iLine)
{
	Point3D * pPt1 = new Point3D(), *pPt2 = new Point3D();
	pPt1 = iLine.GetPt1();
	pPt2 = iLine.GetPt2();
	Set(pPt1, pPt2);
	delete pPt1;
	delete pPt2;
	return *this;
}

