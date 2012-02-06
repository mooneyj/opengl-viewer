#ifndef _Object_h
#define _Object_h
#include <Mat3x1.h>
#include <Vector3.h>
class Object
{
public:
	//Object();
	Object(Mat3x1 *ipColor);
	virtual ~Object();
	virtual void Draw() = 0;
	Mat3x1* GetColor() const;
	Object(const Object& iObj);
	void SetColor(Mat3x1 *ipM);
	virtual void Translate(Vector3 &iDir, double idist) = 0;
private:
	Mat3x1					*_mpColor;
};

#endif
