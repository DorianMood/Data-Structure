#include <iostream>
#include <fstream>
#include <string>
#include <list>

int main()
{
	std::ifstream f("data.txt", std::ifstream::in);

	int rowLength = 0;

	std::list<int*> matrix;

	std::string line;
	while (std::getline(f, line))
	{
		if (!rowLength)
			rowLength = std::count(line.begin(), line.end(), ',') + 1;
		int* row = new int[rowLength];

		std::string tmp = "";
		int index = 0;
		for (std::string::iterator it = line.begin(); it != line.end(); it++)
		{
			if ((*it) >= '1' && (*it) <= '9')
				tmp += *it;
			else
			{
				row[index] = std::stoi(tmp);
				matrix.push_back(row);
				tmp = "";
			}
		}
	}

	// Calculate addition and transpose of given matrix
}
