
#ifndef _ListDefinition_h
#define _ListDefinition_h
#include <ListIterator.h>

class ListDefnition
{
public:
	void Add(Type *pType);

private:
	ListIterator *				_head;
	ListIterator *				_tail;
	ListIterator *				_ptr;
};
void ListDefnition::Add(Type *pNewType)
{
	if(NULL == _head)
	{
		_head->Set(pNewType);
	}
	_tail->Next(pNewType);
	_tail->Set(pNewType);
}

#endif
