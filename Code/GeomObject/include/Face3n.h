
#ifndef _Face3n_h
#define _Face3n_h

#include <Object.h>
#include <Mat3x1.h>
#include <Triangle.h>

class Face3n : public Object
{
public:
	Face3n(TriangleR iTr, Mat3x1 &iColorMatrix);
	virtual void Draw();
private:
	TriangleR _tr;
};


#endif