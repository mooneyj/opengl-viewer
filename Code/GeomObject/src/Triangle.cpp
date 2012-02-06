#include <Triangle.h>
#include <Point3D.h>
#include <glut.h>

void TriangleR::Draw()
{
	if(_tr)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(GetColor()->GetAt(0), GetColor()->GetAt(1), GetColor()->GetAt(2));
		glVertex3f(_tr->GetAt(0).GetX(), _tr->GetAt(0).GetY(), _tr->GetAt(0).GetZ());
		glVertex3f(_tr->GetAt(1).GetX(), _tr->GetAt(1).GetY(), _tr->GetAt(1).GetZ());
		glVertex3f(_tr->GetAt(2).GetX(), _tr->GetAt(2).GetY(), _tr->GetAt(2).GetZ());
		glEnd();
	}
}

TriangleR::TriangleR(Point3D *ipPt1, Point3D *ipPt2, Point3D *ipPt3, Mat3x1 &iColorMatrix):
Object(&iColorMatrix)
{
	_tr = new Triangle();
	if(_tr)
	{
		_tr->SetAt(0, ipPt1);
		_tr->SetAt(1, ipPt2);
		_tr->SetAt(2, ipPt3);
	}
}

TriangleR::TriangleR(Point3D *ipPts, Mat3x1 &iColorMatrix):
Object(&iColorMatrix),
_tr(new Triangle(ipPts))
{
}
TriangleR::~TriangleR()
{
	delete _tr;
}
void TriangleR::Set(Point3D *ipPts)
{
	if(_tr)
	{
		_tr->SetAt(0, &ipPts[0]);
		_tr->SetAt(1, &ipPts[1]);
		_tr->SetAt(2, &ipPts[2]);
	}
}

void TriangleR::SetTriangle(Triangle &iTr)
{
	if(_tr)
		*_tr = iTr;
}
Triangle TriangleR::GetTriangle() const
{
	return *_tr;
}
TriangleR::TriangleR(const TriangleR &iTr):
Object(iTr.GetColor())
{
	_tr = new Triangle(iTr.GetTriangle());
}
void TriangleR::Translate(Vector3 &iDir, double idist)
{
	if(_tr)
	{
		int nMaxSize = _tr->GetMaxSize();
		for(int i = 0; i < nMaxSize; i++)
		{
			_tr->GetAt(i).Translate(iDir,idist);
		}
	}
}


