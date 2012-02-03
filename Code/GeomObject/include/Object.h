#ifndef _Object_h
#define _Object_h
#include <Mat3x1.h>
class Object
{
public:
	//Object();
	Object(Mat3x1 imColor);
	virtual ~Object();
	virtual void Draw() = 0;
	Mat3x1& GetColor() const;
	Object(const Object& iObj);
	void SetColor(Mat3x1 iM);
private:
	Mat3x1					*_mColor;
};

#endif
