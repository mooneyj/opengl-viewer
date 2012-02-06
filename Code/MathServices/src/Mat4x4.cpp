#include <Mat4x4.h>

Mat4x4::Mat4x4(double *iArr):
MatrixDefinition(iArr)
{
}

Mat4x4::Mat4x4():
MatrixDefinition()
{
}
Mat4x4::Mat4x4(const Mat4x4 &iM):
MatrixDefinition()
{
	for(int i = 0; i < GetNbRows(); i++)
		for(int j = 0; j < GetNbColumns(); j++)
			SetAt(i,j,iM.GetAt(i,j));
}
Mat4x4& Mat4x4::operator=(const Mat4x4 &iM)
{
	for(int i = 0; i < GetNbRows(); i++)
		for(int j = 0; j < GetNbColumns(); j++)
			SetAt(i,j,iM.GetAt(i,j));
	return *this;
}
Mat4x4& Mat4x4::operator=(const MatrixDefinition &iM)
{
	for(int i = 0; i < GetNbRows(); i++)
		for(int j = 0; j < GetNbColumns(); j++)
			SetAt(i,j,iM.GetAt(i,j));
	return *this;
}

Mat4x4 Mat4x4::operator*(const Mat4x4 &iM)
{
	MatrixDefinition<4,4> m1(*this),m2(iM),m3;
	m3 = m1*m2;
	Mat4x4 mRetMatx;
	mRetMatx = m3;
	return mRetMatx;
}

