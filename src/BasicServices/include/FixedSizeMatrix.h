
#ifndef _ConstSizeVector_h
#define _ConstSizeVector_h

template <typename T, size_t nMaxSize>
class FixedSizeMatrix
{
private:
	T arr[nMaxSize];
public:
	FixedSizeMatrix(T *iArr)
	{
		for(int i = 0; i < nMaxSize; i++)
			arr[i] = iArr[i];
	};
	FixedSizeMatrix()
	{
	};
	virtual ~FixedSizeMatrix()
	{
	};
	T GetAt(int iLocation) const
	{
		if((iLocation-1) > nMaxSize)
			throw 1;
		return arr[iLocation-1];
	}
	void SetAt(int iLocation, T val)
	{
		if((iLocation-1) > nMaxSize)
			throw 1;
		arr[iLocation-1] = val;
	}	 
	T& operator[](int nIndex)
	{
		return arr[nIndex-1];
	}
	T& operator=(T &iT)
	{
		for(int i = 0; i < nMaxSize; i++)
			arr[i] = iT[i+1];
	}
};

#endif
