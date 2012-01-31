#include <Face1n.h>

Face1n::Face1n(TriangleR iTr, Vector3 iNorm, Mat3x1 &iColorMatrix):
Object(iColorMatrix),
_tr(iTr),
_norm(iNorm)
{
	_tr.SetColor(iColorMatrix);
}

void Face1n::Draw()
{
	_tr.Draw();
}
Face1n::Face1n(const Face1n& iFace):
Object(iFace.GetColor()),
_tr(iFace.GetTriangleR()),
_norm(iFace.GetNorm())
{
	_tr.SetColor(iFace.GetColor());
}
void Face1n::SetColor(Mat3x1 iM)
{
	_tr.SetColor(iM);
}

TriangleR Face1n::GetTriangleR() const
{
	return _tr;
}
void Face1n::SetTriangleR(TriangleR iTr)
{
	_tr = iTr;
}

Vector3 Face1n::GetNorm() const
{
	return _norm;
}
void Face1n::SetNorm(Vector3 iNorm)
{
	_norm = iNorm;
}

