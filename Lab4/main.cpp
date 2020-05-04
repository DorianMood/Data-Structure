#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

int main()
{
	std::ifstream f("data.txt", std::ifstream::in);

	int rowLength = 0;

	std::list<int*> matrix;
	std::map<const std::pair<int, int>, int> cells;

	std::string line;
	while (std::getline(f, line))
	{
		int x, y;
		int numberIndex = 0;

		std::string tmp = "";
		int index = 0;
		for (std::string::iterator it = line.begin(); it != line.end(); it++)
		{
			if (*it < '0' || *it > '9')
				continue;

			tmp += *it;
			switch (numberIndex++)
			{
			case 0:
				x = std::stoi(tmp);
			case 1:
				y = std::stoi(tmp);
			case 2:
				const std::pair<int, int> coords = std::make_pair(x, y);
				cells.insert(std::make_pair(coords, std::stoi(tmp)));
			default:
				break;
			}
			tmp = "";
		}
	}

	// Calculate addition and transpose of given matrix
}
