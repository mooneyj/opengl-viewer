#include <Object.h>


Object::Object(Mat3x1 *ipColor)
{
	double arrCol[3] = {0,0,1};
	if(ipColor)
	{
		arrCol[0] = (*ipColor)[0];
		arrCol[1] = (*ipColor)[1];
		arrCol[2] = (*ipColor)[2];
	}
	Mat3x1 mColor(arrCol);
	_mpColor = new Mat3x1(mColor);
}
Object::~Object()
{
	delete _mpColor;
}
Mat3x1* Object::GetColor() const
{
	return _mpColor;
}
void Object::SetColor(Mat3x1 *ipM)
{
	*_mpColor = *ipM;
}

Object::Object(const Object& iObj)
{
	_mpColor = new Mat3x1(*(iObj.GetColor()));
}


