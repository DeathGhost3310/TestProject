#include <vector>
#include <iostream>
#include <list>
#include <iterator>

template <typename T>
class Map
{
public:

	Map(int xmax, int yMax)
	    :xy(xmax * yMax)
	{	
		std::cout << __FUNCTION__ << std::endl;
		NewArray(xmax, yMax);
	};


	~Map()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	T getValue(int x, int y) {
		int TV;
		std::list <T> Tarr = array;
		if(x <= 0 && y <= 0){
           return array.front();
		}
		if(x > 0 && y > 0){
		for(int i = 0;i < ((ym / xm)* x + y);i++){
          Tarr.pop_front();
		}
		}
		if(x <= 0 && y > 0){
          for(int i = 0;i < y;i++){
            Tarr.pop_front();
		  }
		  return Tarr.front();
		}
		if(x > 0 && y <= 0){
          for(int i = 0;i < x * ym;i++){
			Tarr.pop_front();
		  }
		  return Tarr.front();
		}
		if(x == xm && y == ym){
          return Tarr.back();
		}
		
		
		TV = Tarr.front();
		return TV;
		
	};
	void setValue(int x, int y, T value) {
	 std::list <T> Tarr = array;
	
      for(int i = 0;i < ym / xm * x + y;i++){
        Tarr.pop_front();
	  }
	  Tarr.push_front(value);
	  std::list <T> Tarr2 = array;
	  Tarr.merge(Tarr2);
	  Tarr.unique();
	  array = Tarr;
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
private:
	std::list<T> array;	
	//std::list<T> array; ��� ��������? ����� ����� vector ����� list?
	int xm = 0;
	int ym = 0;	
	int xy = 0;
};


