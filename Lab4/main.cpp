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
			{
				if (tmp != "")
				{
					switch (numberIndex++)
					{
					case 0:
						x = std::stoi(tmp);
						break;
					case 1:
						y = std::stoi(tmp);
						break;
					case 2:
						cells.insert(std::make_pair(std::make_pair(x, y), std::stoi(tmp)));
						break;
					default:
						break;
					}
					tmp = "";
				}
				continue;
			}

			tmp += *it;
		}
		cells.insert(std::make_pair(std::make_pair(x, y), std::stoi(tmp)));
	}

	// Calculate addition and transpose of given matrix

	return 0;
}
