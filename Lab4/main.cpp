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
	
	// Transpose

	std::map<const std::pair<int, int>, int> transpose;

	for (auto cell : cells)
	{
		transpose.insert(std::make_pair(std::make_pair(cell.first.second, cell.first.first), cell.second));
	}

	std::cout << std::endl;
	display(transpose);

	// Multiplication

	int* tmp = new int[cells.size()];
	int i = 0;
	for (auto cell : cells)
	{
		tmp[i++] = (int) cell.second;
	}

	std::map<const std::pair<int, int>, int> multiplication;

	// get shape
	std::pair<int, int> shape = std::make_pair(0, 0);
	for (auto cell : cells)
	{
		if (shape.first < cell.first.first)
			shape.first = cell.first.first;
		if (shape.second < cell.first.second)
			shape.second = cell.first.second;
	}

	for (int i = 1; i <= shape.first; i++)
	{
		for (int j = 1; j <= shape.first; j++)
		{
			auto coords = std::make_pair(i, j);
			multiplication.insert(std::make_pair(coords, 0));
			for (int k = 1; k <= shape.second; k++)
			{
				auto first = std::make_pair(i, k);
				auto second = std::make_pair(k, j);
				multiplication[coords] += cells[first] * transpose[second];
			}
		}
	}


	// MUL = T * M

	std::cout << std::endl;
	display(multiplication);

	return 0;
}
