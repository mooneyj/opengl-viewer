#ifndef _FileReader_h
#define _FileReader_h
#include <STLObject.h>
using namespace std;
class FileReader
{
public:
	FileReader(char *);
	~FileReader();
	string NextWord( string s, bool *empty );
	void GetSTLObject(STLObject& iList);
private:
	void PopulateSTLObject();
	STLObject				*_pStl;
	char						*_pFileName;
	bool						_bStlPopulated;
};

#endif