#include <Object.h>

//Object::Object()
//{
//}

Object::Object(Mat3x1 &imColor)
{
	_mColor.SetAt(1, imColor[1]);
	_mColor.SetAt(2, imColor[2]);
	_mColor.SetAt(3, imColor[3]);
}
Object::~Object()
{
}
Mat3x1 Object::GetColor() const
{
	return _mColor;
}
void Object::SetColor(Mat3x1 iM)
{
	_mColor = iM;
}

Object::Object(const Object& iObj)
{
	_mColor.SetAt(1, iObj.GetColor().GetAt(1));
	_mColor.SetAt(2, iObj.GetColor().GetAt(2));
	_mColor.SetAt(3, iObj.GetColor().GetAt(3));
}


