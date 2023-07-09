#include "Map.h"


#include <iostream>

struct Coord
{
	int x;
	int y;
};

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

		return array[{x, y}];

		
	};
	void setValue(int x, int y, T value) {
		array[{x, y}] = value;

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
		// T Tarr[xm][ym];

		// for(int i = 0;i < xm,i++){
		// 	for(int j = 0, j < ym,j++){
		//        Tarr[i][j] = array[i][j];
		// 	}
		// }
		T* Tarr = array;
		xy = (xmax * yMax);
		NewArray(xmax, ymax);

		for (int i = 0; i < xy; i++) {
			array[i] = Tarr[i];
		}

		DeleteArray(Tarr);
	};

private:
	T* CleanArray(T* arr) {
		for (int i = 0; i < xy; i++)
		{
			arr[i] = 0;
		}
		return arr;
	}


	void NewArray(int xmax, int yMax) {
		array = new T[xmax * yMax];
		xm = xmax;
		ym = yMax;
		CleanArray(array);
	}

private:
	//как внутри устроен. Двоичное дерево.
	std::map<Coord, T> array;

	int xm = 0;
	int ym = 0;
	int xy = 0;
};


