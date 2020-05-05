#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

void display(std::map<const std::pair<int, int>, int>& cells)
{
	for (const auto cell : cells)
	{
		std::cout << cell.first.first << " " << cell.first.second << " " << cell.second << std::endl;
	}
}

int main()
{
	std::ifstream f("data.txt", std::ifstream::in);

	int rowLength = 0;

	std::map<const std::pair<int, int>, int> cells;

	std::string line;
	while (std::getline(f, line))
	{
		int x, y;
		int index = 0;

		std::string tmp = "";
		for (std::string::iterator it = line.begin(); it != line.end(); it++)
		{
			if (*it < '0' || *it > '9')
			{
				if (tmp != "")
				{
					switch (index++)
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

	display(cells);
	
	// Addition



	// Transpose

	std::map<const std::pair<int, int>, int> transpose;

	for (auto cell : cells)
	{
		transpose.insert(std::make_pair(std::make_pair(cell.first.second, cell.first.first), cell.second));
	}

	display(transpose);


	return 0;
}
