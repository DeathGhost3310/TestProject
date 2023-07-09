
#include <iostream>

template <typename T>
class Map
{
public:

	Map(int xmax, int yMax){
		T array[xmax][yMax];
		int* a = &xm;
		int* b = &ym;
		*a = xmax;
		*b = yMax;
	};
	T getValue(int x, int y){
       if(x < xm && y < ym){
         return array[x][y];
	   }
	   else{
		std::cout << "not of range" << std::endl;
	   }
	   return 0;
	};
	void setValue(int x, int y, T empty){
		if(x < xm && y < ym){
		array[x][y] = empty;
		}
	};
	static void print(int x, int y){
		std::cout << array[x][y] << std::endl;
	};
	void changeSize(int xmax, int ymax){
		T Tarr[xmax][ymax];
		for(int i = 0;i < xmax,i++){
			for(int j = 0, j < ymax,j++){
               Tarr[i][j] = array[i][j];
			}
		}
		delete array;
		array[xmax][ymax];
		for(int i = 0;i < xmax,i++){
			for(int j = 0, j < ymax,j++){
               array[i][j] = Tarr[i][j];
			}
		}
		delete Tarr;
	};
private:	
	T *array;	//T **array
    int xm = 0;
	int ym = 0;

};

