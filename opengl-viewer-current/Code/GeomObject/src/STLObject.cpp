#include <STLObject.h>


STLObject::STLObject(Mat3x1 iMat):
Object(&iMat)
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

void STLObject::DestroyFaces()
{
	_list.Destroy();
}

STLObject::STLObject(const STLObject& iStlObj):
Object((iStlObj.GetColor()))
{
}
IteratorFace1n *STLObject::GetFaceIterator() const
{
	return _list.Head();
}
STLObject& STLObject::operator=(const STLObject& iStlObj)
{
	_list.Empty();
	IteratorFace1n *pite = iStlObj.GetFaceIterator();
	while(pite)
	{
		_list.Add(pite->Get());
		pite = pite->Next();
	}
	return *this;
}
void STLObject::Translate(Vector3 &iDir, double idist)
{
}