#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileReader
{
private:
	std::vector<std::vector<int>> _tabFile;

public :
	FileReader();
	
	void readFile(std::string path);
	bool compareFileRead(std::vector<std::vector<int>> startFile);
};

