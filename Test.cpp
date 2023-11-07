#include "Test.h"

Test::Test() {};

void Test::fileReader()
{
	FileReader o_file = FileReader();

	std::vector<std::vector<int>> start =
	{
		{0, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 3, 5, 2, 0, -1},
		{0, 1, 0, 1, 0, 0, 2, 2, 2, 0, 0, 4, 4, 4, 0, -1},
		{0, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 3, 5, 2, 0, -1},
		{0, 1, 0, 1, 0, 0, 2, 2, 2, 0, 0, 4, 4, 4, 0, -1},
		{0, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 3, 5, 2, 0, -1},
	};

	o_file.readFile("Files/test.txt");

	std::cout << "Test File Reader : " << (o_file.compareFileRead(start) ? "SUCCESS" : "FAILURE" ) << std::endl;
}

void Test::normalizeVector()
{
	Math::Vector2 start = Math::Vector2(1 / sqrt(2), 1 / sqrt(2));

	Math::Vector2 result = Math::Vector2(1, 1);

	result.normalizeVector();

	std::cout << "Test Normalize Vector : " << (start.compareVector(start) ? "SUCCESS" : "FAILURE") << std::endl;
}