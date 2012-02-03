#include <Object.h>


Object::Object(Mat3x1 imColor)
{
	_mColor = new Mat3x1(imColor);
}
Object::~Object()
{
	delete _mColor;
}
Mat3x1& Object::GetColor() const
{
	return *_mColor;
}
void Object::SetColor(Mat3x1 iM)
{
	*_mColor = iM;
}

Object::Object(const Object& iObj)
{
	_mColor = new Mat3x1(iObj.GetColor());
}


