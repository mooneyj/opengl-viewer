
#ifndef _BasicSolve_h
#define _BasicSolve_h
#include <BasicDefs.h>

class BasicSolve
{
public:
	BasicSolve(){_dValue = 0; _bIsSolved = FALSE;};
	virtual ~BasicSolve()=0{};
	virtual void Solve()=0;
	virtual double GetValue(){return _dValue;};
	virtual void SetValue(double iV){_dValue=iV;};
	virtual void Solved(){_bIsSolved = TRUE;};
	virtual Bool IsSolved(){return _bIsSolved;};
private:
	double _dValue;
	Bool _bIsSolved;
};

#endif
