// This code belongs to Vinayak Kane

#include "Determinant.h"

Determinant::Determinant():
BasicSolve()
{
}
void Determinant3x3::Solve()
{
	SetValue(ComputeDeterminant3x3(_m));
	Solved();
}
Determinant3x3::Determinant3x3()
:Determinant()
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			_m[i][j] = 0;	
}

Determinant3x3::Determinant3x3(double im[3][3])
:Determinant()
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			_m[i][j] = im[i][j];
}

void Determinant3x3::SetRow(Count iCount, double im[])
{
	for(int i = 0; i < 3; i++)
		_m[iCount-1][i] = im[i];
}

void Determinant3x3::SetColumn(Count iCount, double im[])
{
	for(int i = 0; i < 3; i++)
		_m[i][iCount-1] = im[i];
}


double Determinant3x3::operator+(Determinant3x3&iD)
{
	if(!iD.IsSolved())
		iD.Solve();
	if(!this->IsSolved())
		this->Solve();

	return (iD.GetValue() + this->GetValue());
}

double Determinant3x3::operator/(Determinant3x3&iD)
{
	if(!iD.IsSolved())
		iD.Solve();
	if(!this->IsSolved())
		this->Solve();

	return (iD.GetValue() / this->GetValue());
}