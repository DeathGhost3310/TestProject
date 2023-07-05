#include "Map.h"

Map::Map(int xmax, int yMax)
{
	array = new bool*[xmax];
	for (int i; i < xmax; ++i)
	{
		array[i] = new bool[yMax];
	}


	for (int i; i < xmax; ++i)
	{
		for (int j; j < yMax; ++j)
		{
			array[i][j] = false;
		}
	}
}

bool Map::getValue(int x, int y)
{
	if (x < xmax && y < 10)
	{

		return array[x][y];

	}
	else{
		std::cout << "out of range" << std::endl;
	}
	return 0;
}

void Map::setValue(int x, int y, bool empty)
{

	array[x][y] = empty;
}
 void Map::print()
{
	std::cout << "print" << std::endl;
}

void Map::changeSize(int xmax, int yMax)
{
	delete array;
	array = new T*[xmax];
	for (int i; i < xmax; ++i)
	{
		array[i] = new T[yMax];
	}
}