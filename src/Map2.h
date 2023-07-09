#include <vector>
#include <iostream>

template <typename T>
class Map
{
public:

	Map(int xmax, int yMax)
		:xy(xmax* yMax)
	{
		std::cout << __FUNCTION__ << std::endl;
		NewArray(xmax, yMax);
	};


	~Map()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	T getValue(int x, int y) {
		return array[(ym / xm) * x + y];
		
	};
	void setValue(int x, int y, T value) {
		array.push_back[(ym / xm) * x + y] = value;
	};
	
	void print() {
		for (int i = 0; i < xm; i++) {
			for (int j = 0; j < ym; j++) {
				std::cout << array[(ym / xm) * i + j] << "  ";
			}
			std::cout << std::endl;
		}
	};



	void changeSize(int xmax, int ymax) {
		
		T* Tarr = array;
		
		for (size_t i = 0; i < (xmax * ymax) - xy) ; i++)
		{
			array.push_back(0);
		}
		xy = (xmax * yMax);
		xm = xmax;
		ym = yMax;

	};

private:
	
	

	void NewArray(int xmax, int yMax) {
		
		xm = xmax;
		ym = yMax;
		//array.reserve(); что такое? зачем нужен?
		for (size_t i = 0; i < xy; i++)
		{
			array.push_back(0);
		}
	}

private:
	std::vector<T> array;	
	//std::list<T> array; как работает? когда нужен vector когда list?
	int xm = 0;
	int ym = 0;
	int xy = 0;
};


