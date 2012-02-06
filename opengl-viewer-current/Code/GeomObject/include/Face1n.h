
#ifndef _Face1n_h
#define _Face1n_h

#include <Object.h>
#include <Vector3.h>
#include <Mat3x1.h>
#include <Triangle.h>

class Face1n : public Object
{
public:
	virtual ~Face1n();
	Face1n(TriangleR iTr, Vector3 iNorm, Mat3x1 &iColorMatrix);
	virtual void Draw();
	Face1n(const Face1n& iFace);
	TriangleR GetTriangleR() const;
	void SetTriangleR(TriangleR &iTr);
	Vector3 GetNorm() const;
	void SetNorm(Vector3 &iNorm);
	void SetColor(Mat3x1 &iM);
	virtual void Translate(Vector3 &iDir, double idist);
private:
	TriangleR					*_tr;
	Vector3						*_norm;
};


#endif