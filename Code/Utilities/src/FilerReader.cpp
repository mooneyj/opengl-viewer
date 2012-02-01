
#include <FileReader.h>
#include <string>
#include <iostream>
#include <Face1n.h>
#include <Triangle.h>
#include <Point3D.h>
using namespace std;
FileReader::~FileReader()
{
}
FileReader::FileReader(char *iFilename)
{
	int nCount = 0;
	_file.open(iFilename,ios::in);
	double d1[3] = {1,0,0};
	Mat3x1 m1(d1);
	Point3D pt1, pt2, pt3;
	Vector3 norm;
	TriangleR tr1(&pt1, &pt2, &pt3, m1);
	Face1n face(tr1, norm, m1);
	if (_file.is_open())
  {
		string line;
		bool newSolid = false;
		bool newFace = false;
		bool newVertex = false;
		while(!_file.eof())
		{
			nCount++;
			getline(_file,line);
			size_t foundSolid = line.find("solid");
			if(foundSolid!=string::npos)
				newSolid = true;

			size_t foundFace = line.find("facet");
			if(foundFace!=string::npos)
				newFace = true;
		if(true == newFace)
		{
		}
		else
		{
		}

			//cout << line << endl;
		}
    _file.close();
  }
	cout << endl;
	cout << endl;
	cout << "The total #lines: " << nCount << endl;
}
