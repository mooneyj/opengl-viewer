
#ifndef _ConstSizeVector_h
#define _ConstSizeVector_h

template <class T, size_t MAX_SIZE>
class FixedSizeMatrix
{
private:
	T *_arr[MAX_SIZE];
public:
	FixedSizeMatrix(T *iArr)
	{
		for(int i = 0; i < MAX_SIZE; i++)
			_arr[i] = new T(iArr[i]);
	};
	FixedSizeMatrix()
	{
		for(int i = 0; i < MAX_SIZE; i++)
			_arr[i] = new T;
	};
	virtual ~FixedSizeMatrix()
	{
		for(int i = 0; i < MAX_SIZE; i++)
			delete _arr[i];
	};
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
	T& operator[](int nIndex)const
	{
		return *_arr[nIndex];
	}
	FixedSizeMatrix(const FixedSizeMatrix &iMatrix)
	{
		for(int i = 0; i < MAX_SIZE; i++)
			_arr[i] = new T(iMatrix[i]);
	}
	FixedSizeMatrix& operator=(const FixedSizeMatrix &iT)
	{
		for(int i = 0; i < MAX_SIZE; i++)
			*_arr[i] = iT.GetAt(i);
		return *this;
	}
};

#endif
