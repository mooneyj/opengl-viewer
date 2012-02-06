
#include <Point3D.h>
Point3D::Point3D():
Object(NULL),
_pMatrix(new Mat3x1)
{
}
Point3D::Point3D(double iX, double iY, double iZ):
Object(NULL),
_pMatrix(new Mat3x1)
{
	if(_pMatrix)
	{
		_pMatrix->SetAt(0, &iX);
		_pMatrix->SetAt(1, &iY);
		_pMatrix->SetAt(2, &iZ);
	}
}
Point3D::Point3D(double *arr):
Object(NULL),
_pMatrix(new Mat3x1)
{
	Set(arr);
}
Point3D::~Point3D()
{
	delete _pMatrix;
}

void Point3D::Set(double *arr)
{
	if(_pMatrix)
	{
		_pMatrix->SetAt(0, &arr[0]);
		_pMatrix->SetAt(1, &arr[1]);
		_pMatrix->SetAt(2, &arr[2]);
	}
}

void Point3D::Set(double idX, double idY, double idZ)
{
	if(_pMatrix)
	{
		_pMatrix->SetAt(0, &idX);
		_pMatrix->SetAt(1, &idY);
		_pMatrix->SetAt(2, &idZ);
	}
}

double Point3D::GetX() const
{
	double dRetVal(-1);
		if(_pMatrix)
			dRetVal = _pMatrix->GetAt(0);
	return dRetVal;
}
double Point3D::GetY() const
{
	double dRetVal(-1);
		if(_pMatrix)
			dRetVal = _pMatrix->GetAt(1);
	return dRetVal;
}
double Point3D::GetZ() const
{
	double dRetVal(-1);
		if(_pMatrix)
			dRetVal = _pMatrix->GetAt(2);
	return dRetVal;
}

Point3D::Point3D(const Point3D& iPt):
Object(NULL),
_pMatrix(new Mat3x1)
{
	double d1 = iPt.GetX();
	double d2 = iPt.GetY();
	double d3 = iPt.GetZ();

	if(_pMatrix)
	{
		_pMatrix->SetAt(0, &d1);
		_pMatrix->SetAt(1, &d2);
		_pMatrix->SetAt(2, &d3);
	}
}
void Point3D::Translate(Vector3 &iDir, double idist)
{
	double d1 = _pMatrix->GetAt(0)+iDir.GetX();
	double d2 = _pMatrix->GetAt(1)+iDir.GetY();
	double d3 = _pMatrix->GetAt(2)+iDir.GetZ();
	if(_pMatrix)
	{
		_pMatrix->SetAt(0, &d1);
		_pMatrix->SetAt(1, &d2);
		_pMatrix->SetAt(2, &d3);
	}
}
void Point3D::Draw()
{
}

Point3D& Point3D::operator=(const Point3D& ipt)
{
	Set(ipt.GetY(),ipt.GetY(),ipt.GetX());
	return *this;
}
