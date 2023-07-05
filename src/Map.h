
#include <iostream>

template <typename T>
class Map
{
public:

	Map(int xmax, int yMax);
	T getValue(int x, int y);
	void setValue(int x, int y, T empty);
	static void print();
	void changeSize(int xmax, int yMax);
private:	
	T **array;	


};

