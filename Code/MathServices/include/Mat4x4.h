#ifndef _Mat4x4_h
#define _Mat4x4_h

#include <MatrixDefinition.h>

class Mat4x4 : public MatrixDefinition<4,4>
{
public:
	Mat4x4(double *iArr);
	Mat4x4();
	Mat4x4 operator*(const Mat4x4 &iM);
	Mat4x4(const Mat4x4 &iMatrix);
	Mat4x4& operator=(const Mat4x4 &iM);
	Mat4x4& operator=(const MatrixDefinition &iM);
};
#endif 

