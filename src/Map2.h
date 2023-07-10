#include <vector>
#include <iostream>
#include <list>
#include <iterator>

template <typename T>
class Map2
{
public:

	Map2(int xmax, int yMax)
	    :xy(xmax * yMax)
	{	
		std::cout << __FUNCTION__ << std::endl;
		NewArray(xmax, yMax);
	};


	~Map2()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	T getValue(int x, int y) {
		
		auto num = getNum(x , y);
		auto it = array.begin();
		for (int i = 0; i < num; i++)
		{
			it++;
		}
		
		return *it;
		
	};
	void setValue(int x, int y, T value) {
		auto num = getNum(x, y);
		auto it = array.begin();
		
		for(int i = 0; i < num; ++i) {
			++it;
		}

		*it = value;
	};
	
	void print() {
		std::list <T> Tarr = array;
		for(int i = 0;i < xy;i++){
          std::cout << Tarr.front() << "  ";
		  if(i == (xy / 2)){
			std::cout << std::endl;
		  }
		  Tarr.pop_back();
		}
	};
	void changeSize(int xmax, int ymax) {
		for (size_t i = 0; i < ((xmax * ymax) - xy) ; i++)
		{
			array.push_back(0);
		}
		xy = (xmax * ymax);
		xm = xmax;
		ym = ymax;
	};

private:
	void NewArray(int xmax, int yMax) {
		
		xm = xmax;
		ym = yMax;
	    xy = yMax * xmax;
		//array.reserve(); ��� �����? ����� �����?
		for (int i = 0; i < xy; i++)
		{
			array.push_back(0);
		}
	}
	int getNum(int x, int y)
	{
		return (ym / xm)* x + y;
	}
private:
	std::list<T> array;	
	//std::list<T> array; ��� ��������? ����� ����� vector ����� list?
	int xm = 0;
	int ym = 0;	
	int xy = 0;
};


