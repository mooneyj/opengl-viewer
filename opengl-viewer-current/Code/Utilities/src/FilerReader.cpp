
#include <FileReader.h>
#include <iostream>
#include <Face1n.h>
#include <Triangle.h>
#include <Point3D.h>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

char TAB = 9;
inline string GetNextWord(string s, size_t &curIndex);
inline size_t GetSizeOfNextWord(string s, size_t &curIndex);
inline double StrToDouble(string str);
Point3D p1(0,0,0);
Point3D p2(0,0,0);
Point3D p3(0,0,0);
Point3D pts3D[3]={p1,p2,p3};
double colUtil[3] = {1,0,0};
Mat3x1 mCol(colUtil);
TriangleR *tri1 = 0;//(&p1,&p2,&p3,mCol);
Vector3 *norm = 0;//(0,0,0);
Face1n *f1 = 0;//(tri1,*norm, mCol);
//STLObject stlObj(mCol);
bool bSolid = false, bFacet = false;
int nbVertex = 0;
FileReader::~FileReader()
{
//	delete _pStl;
}
FileReader::FileReader(char *iFilename):
_pFileName(iFilename),
_pStl(NULL),
_bStlPopulated(false)
{
	double col1[3] = {1,0,0};
	Mat3x1 mCol1(col1);
	_pStl = new STLObject(mCol1);
}
		
void FileReader::GetSTLObject(STLObject& iList)
{
	double col1[3] = {1,0,0};
	Mat3x1 mCol1(col1);
	//STLObject retSTL(mCol1);
	if(!_bStlPopulated)
	{
		PopulateSTLObject();
		_bStlPopulated = true;
	}
	iList = *_pStl;
	//_pStl->DestroyFaces();
	//return retSTL;
}

void FileReader::PopulateSTLObject()
{
	fstream file;
	file.open(_pFileName);
	if(file)
	{
		while(!file.eof())
		{
			string line;
			getline(file,line);
			size_t index = 0;
			string word1 = GetNextWord(line, index);
			if("solid" == word1)
			{
				bSolid = true;
				continue;
			}
			else if("facet" == word1)
			{
				bFacet = true;
				double values[3]={};
				int i = 0;
				for(;;)
				{
					string word = GetNextWord(line, index);
					if(word == "normal")
						continue;
					else
					{
						values[i] = StrToDouble(word);/*******function to convert string to double**********/
						i++;
					}
					if(i >= 3)
						break;
				}
				norm = new Vector3(values[0],values[1],values[2]);
				//norm.Set(values[0],values[1],values[2]);
				continue;
			}
			else if("vertex" == word1)
			{
				double values[3]={};
				int i = 0;
				for(;;)
				{
					string word = GetNextWord(line, index);
					if(word == "vertex")
						continue;
					else
					{
						values[i] = StrToDouble(word);/*******function to convert string to double**********/
						i++;
					}
					if(i >= 3)
						break;
				}	
				pts3D[nbVertex].Set(values);
				nbVertex = nbVertex++;
				/*if(nbVertex >= 3)
				{
					tri1.Set(pts3D);
					nbVertex = 0;
				}*/
				continue;
			}
			else if("endloop" == word1)
			{
				double col1[3] = {1,0,0};
				Mat3x1 mCol1(col1);
				tri1 = new TriangleR(pts3D,mCol1);
				/*if(tri1)
					tri1->Set(pts3D);*/
				nbVertex = 0;
			}
			else if("endfacet" == word1)
			{
				double col1[3] = {1,0,0};
				Mat3x1 mCol1(col1);
				f1 = new Face1n(*tri1,*norm,mCol1);
				//f1.SetNorm(*norm);
				delete norm;
				norm = 0;
				//f1.SetTriangleR(*tri1);
				delete tri1;
				tri1 = 0;
				if(_pStl)
					_pStl->AddFace(f1);
				//delete f1;
				f1 = 0;
			}
		}
		file.close();
	}
	_bStlPopulated = true;
}


inline size_t GetSizeOfNextWord(string s, size_t &curIndex)
{
	size_t size = 0;
	size_t strSize = s.size();
	for(;;)
	{
		if(' ' == s[curIndex] || TAB ==  s[curIndex])
			curIndex++;
		else
			break;
	}
	size_t localCurrIndex = curIndex;
	for(;;)
	{
		if(localCurrIndex < strSize)
		{
			if(' ' != s[localCurrIndex])
			{
				size++;
				localCurrIndex++;
			}
			else
				break;
		}
		else
			break;
	}
	return size;
}
inline string GetNextWord(string s, size_t &curIndex)
{
	size_t nextWordSize = GetSizeOfNextWord(s,curIndex);
	string sRet;
	if(0 >= nextWordSize)
		return sRet;
	size_t startIndex = curIndex;
	char *thisword = new char[nextWordSize+1];
	for(size_t i = 0; i < nextWordSize; i++)
	{
		thisword[i] = s[i+startIndex];
		curIndex++;
	}
	thisword[nextWordSize] = '\0';
	sRet = string(thisword);
	delete []thisword;
	return sRet;
}

inline double StrToDouble(string str)
{
	const char* ch = str.c_str();
	double nVal = atof(ch);
	//scanf_s(ch,"%f",&nVal);
	return nVal;
}
