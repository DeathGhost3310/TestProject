
#include <iostream>
#include <vector>

template <typename T>
class Map
{
public:

	Map(int xmax, int yMax){
		NewArray(xmax, yMax);	
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
		} else{
			std::cout << "eror" << std::endl;
		}

	};
	 void print(){
		 for (int i = 0; i < xm; i++) {
			 for (int j = 0; j < ym; j++) {
				std::cout << array[i][j] << "  ";
	 		}
			 std::cout << std::endl;
		}
	};



	void changeSize(int xmax, int ymax){
		// T Tarr[xm][ym];
		
		// for(int i = 0;i < xm,i++){
		// 	for(int j = 0, j < ym,j++){
        //        Tarr[i][j] = array[i][j];
		// 	}
		// }
		T ** Tarr = array;

		NewArray(xmax,ymax);
		
		for(int i = 0;i < xm,i++){
			for(int j = 0, j < ym,j++){
               array[i][j] = Tarr[i][j];
			}

			
		}

		DeleteArray(Tarr);
	};

private:
	void CleanArray(){
		for (int i = 0; i < xm; i++)
		{
			for (int j = 0; j < ym;j++)
			{
				array[i][j] = 0;
			}
			
		}
		
	}
	void DeleteArray(T** arr){
		for(int i = 0;i < xm,i++){
			delete[] arr[i];
		}
		delete[] arr;
	}

	void NewArray(int xmax, int yMax){
     	array = new T* [xmax];
		for (int i = 0; i < xmax; i++) {
        	array[i] = new T [yMax];
		}
        
		xm = xmax;
		ym = yMax;
		CleanArray();
	}

private:	
	std::vector array;	
    int xm = 0;
	int ym = 0;

};


