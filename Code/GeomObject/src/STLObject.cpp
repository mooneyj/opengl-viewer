#include <STLObject.h>


STLObject::STLObject(Mat3x1 &iMat):
Object(iMat)
{
}
STLObject::~STLObject()
{
	_list.Destroy();
}

void STLObject::Draw()
{
	IteratorFace1n *pite = _list.Head();
	while(pite)
	{
		pite->Get()->Draw();
		pite = pite->Next();
	}
}

void STLObject::AddFace(Face1n *ipFace)
{
	_list.Add(ipFace);
}


