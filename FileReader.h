#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileReader
{
public :
	FileReader();
	
	std::vector<std::vector<int>> readFile(std::string path);
};

