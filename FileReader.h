#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileReader
{
private:
	std::vector<std::vector<int>> _tabFile;
	int _sizeHeight;
	int _sizeWidth;

public :
	FileReader();
	
	void readFile(std::string path);
	bool compareFileRead(std::vector<std::vector<int>> startFile);
};

