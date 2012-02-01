
#ifndef _ListDefinition_h
#define _ListDefinition_h

template <class Type>
class ListIterator
{
public:
	ListIterator()
	{
		_type			= 0;
		_pNext		= 0;
	}
	ListIterator<Type> * Next()
	{
		return _pNext;
	};
	void Next(ListIterator<Type> * ipNext)
	{
		_pNext = ipNext;
		if(_pNext)
			_pNext->Next(0);
	}
	Type* Get()const
	{
		return _type;
	};
	void Set(Type* ipType)
	{
		_type = ipType;
	};
private:
	//int													_id;
	Type*												_type;
	ListIterator<Type>*					_pNext;

};
template <class Type>
class ListDefnition
{
public:
	ListDefnition()
	{
		_head = 0;
		_tail = 0;
	}
	void Add(Type *pNewType)
	{
		ListIterator<Type>*ptr = new ListIterator<Type>;
		if(0 == _head)
		{
			ptr->Set(pNewType);
			_head = ptr;
			_tail = ptr;
			_tail->Next(0);
		}
		else
		{
			ptr->Set(pNewType);
			_tail->Next(ptr);
			_tail = ptr;
			_tail->Next(0);
		}
	}
	void Destroy()
	{
		ListIterator<Type>*ptrCurr = _head;
		ListIterator<Type>*ptrNext = 0;
		while(ptrCurr)
		{
			ptrNext = ptrCurr->Next();
			delete ptrCurr;
			ptrCurr = ptrNext;
		}
	}
	ListIterator<Type>* Head()
	{
		return _head;
	}
private:
	ListIterator<Type>*					_head;
	ListIterator<Type>*					_tail;
};


#endif
