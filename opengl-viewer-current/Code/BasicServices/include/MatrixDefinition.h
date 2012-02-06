#ifndef _MatrixDefinition_h
#define _MatrixDefinition_h

template <int MAX_ROW, int MAX_COL>
class MatrixDefinition
{
private:
	double _arr[MAX_ROW][MAX_COL];
public:
	MatrixDefinition(double *iArr)
	{
		for(int i = 0; i < MAX_ROW; i++)
			for(int j = 0; j < MAX_COL; j++)
				_arr[i][j] = iArr[i*MAX_ROW+j];
	};
	MatrixDefinition()
	{
		for(int i = 0; i < MAX_ROW; i++)
			for(int j = 0; j < MAX_COL; j++)
				_arr[i][j] = 0.;
	};
	virtual ~MatrixDefinition()
	{
	};
	MatrixDefinition(const MatrixDefinition &iMatrix)
	{
		for(int i = 0; i < MAX_ROW; i++)
			for(int j = 0; j < MAX_COL; j++)
				_arr[i][j] = iMatrix.GetAt(i,j);
	}
	double GetAt(size_t i1, size_t i2) const
	{
		return _arr[i1][i2];
	}
	void SetAt(size_t i1, size_t i2, double iVal)
	{
		_arr[i1][i2] = iVal;
	}
	MatrixDefinition& operator=(const MatrixDefinition &iM)
	{
		for(int i = 0; i < MAX_ROW; i++)
			for(int j = 0; j < MAX_COL; j++)
			_arr[i][j] = iM.GetAt(i,j);
		return *this;
	}
	int GetNbRows()const{return MAX_ROW;};
	int GetNbColumns()const{return MAX_COL;};
	MatrixDefinition operator*(const MatrixDefinition &iM)
	{
		MatrixDefinition mRetMatx(iM);
		int r1 = GetNbRows();
		int c1 = GetNbColumns();
		int r2 = iM.GetNbRows();
		int c2 = iM.GetNbColumns();
		if(c1 != r2)
			throw 1;

		for(int i = 0; i < r1; i++)
		{
			for(int j = 0; j < c2; j++)
			{
				double sum = 0;
				for(int k = 0; k < c1; k++)
				{
					sum += GetAt(i,k)*iM.GetAt(k,j);
				}
				mRetMatx.SetAt(i,j, sum);
			}
		}
		return mRetMatx;
	}
	//virtual MatrixDefinition operator*(const MatrixDefinition &iM)=0;
};

#endif

