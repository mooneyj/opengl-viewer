
#ifndef _ConstSizeVector_h
#define _ConstSizeVector_h

template <class T, size_t MAX_SIZE>
class FixedSizeArray
{
private:
	T *_arr[MAX_SIZE];
public:
	FixedSizeArray(T *iArr)
	{
		for(int i = 0; i < MAX_SIZE; i++)
			_arr[i] = new T(iArr[i]);
	};
	FixedSizeArray()
	{
		for(int i = 0; i < MAX_SIZE; i++)
			_arr[i] = new T;
	};
	virtual ~FixedSizeArray()
	{
		for(int i = 0; i < MAX_SIZE; i++)
			delete _arr[i];
	};
	int GetMaxSize()
	{
		return (int)MAX_SIZE;
	}
	T& GetAt(int iLocation) const
	{
		if((iLocation) > MAX_SIZE)
			throw 1;
		return *(_arr[iLocation]);
	}
	void SetAt(int iLocation, T *val)
	{
		if((iLocation) > MAX_SIZE)
			throw 1;
		*(_arr[iLocation]) = *val;
	}
	virtual T& operator[](int nIndex)const
	{
		return *_arr[nIndex];
	}
	FixedSizeArray(const FixedSizeArray &iMatrix)
	{
		for(int i = 0; i < MAX_SIZE; i++)
			_arr[i] = new T(iMatrix[i]);
	}
	virtual FixedSizeArray& operator=(const FixedSizeArray &iT)
	{
		for(int i = 0; i < MAX_SIZE; i++)
			*_arr[i] = iT.GetAt(i);
		return *this;
	}
};

#endif
