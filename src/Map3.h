#include <vector>
#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
struct Cell
{
 int x;
 int y;
 T value;
};

template <typename T>
class Map2
{
public:

	Map2()
	{	
		std::cout << __FUNCTION__ << std::endl;
		
	};


	~Map2()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	
	T getValue(int x, int y) {
		for(auto i  = 0; i < array.size(); ++i ){
			Cell cel = array[i];
			if(cel.x == x  && cel.y == y){
				return cel.value;
			}
		}

		for(const auto& cel : array)
		{
			if(cel.x == x  && cel.y == y){
				return cel.value;
			}
		}

		
		
		std::cout << "no element" << std::endl;
		return 0;
		
	};
	
	void setValue(int x, int y, T value) {

		auto it = array.begin();

		for(;it != array.end(); ++it)
		{
			if(it->x == x && it->y == y){
				it->value = value;
				break;
			}
		}

		if(it == array.end())
		{
			array.push_back(value);
		}
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
	
	
private:
	std::vector<Cell<T>> array;	
};


