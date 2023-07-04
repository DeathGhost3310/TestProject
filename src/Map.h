#include "coord.h"
//x, y от 0 до 10

class Map
{
public:
	bool isEmpty(int x, int y)
	{
		//сделать реализацию
	}
	void setEmpty(int x, int y, bool empty)
	{
		//сделать реализацию
	}
private:
	bool array[10][10];

	
}

int main()
{
	Map map;
	
	map.setEmpty(0, 0, true);

	map.setEmpty(0, 1, true);

	map.setEmpty(0, 3, true);

	map.setEmpty(5, 2, true);

	std:: cout << "0 0" << map.getEmpty(0, 0) << std::endl;
	std:: cout << "2 0" << map.getEmpty(2, 0) << std::endl;
	
	
	
	
}