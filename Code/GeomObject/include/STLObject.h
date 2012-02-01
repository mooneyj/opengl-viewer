#ifndef _STLObject_h
#define _STLObject_h
#include <ListFace1n.h>
#include <Object.h>
#include <Mat3x1.h>

class Face1n;
class STLObject : public Object
{
public:
	STLObject(Mat3x1 &iMat);
	virtual ~STLObject();
	virtual void Draw();
	virtual void AddFace(Face1n *ipFace);
private:
	ListFace1n	_list;
};

#endif

