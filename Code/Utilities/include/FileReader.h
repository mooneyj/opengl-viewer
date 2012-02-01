#ifndef _FileReader_h
#define _FileReader_h
#include <fstream>
class FileReader
{
public:
	FileReader(char *);
	~FileReader();
private:
	std::fstream					_file;
};

#endif