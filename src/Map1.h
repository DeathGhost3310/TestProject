
#include <iostream>

template <typename T>
class Map
{
public:

	Map(int xmax, int yMax)
		:xy(xmax * yMax)
	{

		NewArray(xmax, yMax);	
		
	};
	T getValue(int x, int y){
       if(x < xm && y < ym){
         return array[(ym / xm) * x + y];
	   }
	   else{
		std::cout << "not of range" << std::endl;
	   }
	   return 0;
	};
	void setValue(int x, int y, T value){
		if(x < xm && y < ym){
		  array[(ym / xm) * x + y] = value;
		} else{
			std::cout << "eror" << std::endl;
		}

	};
	 void print(){
		 for (int i = 0; i < xm; i++) {
			 for (int j = 0; j < ym; j++) {
				std::cout << array[(ym / xm) * i + j] << "  ";
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
		T * Tarr = array;
		xy = (xmax * yMax);
		NewArray(xmax,ymax);
        
		for(int i = 0;i < xy;i++){		
               array[i] = Tarr[i];		
		}

		DeleteArray(Tarr);
	};

private:
	T* CleanArray(T* arr){
		for (int i = 0; i < xy; i++)
		{		
				arr[i] = 0;		
		}
		return arr;
	}
	void DeleteArray(T* arr){
		//поменять
		for(int i = 0;i < xy;i++){
			delete[] arr[i];
		}
		delete[] arr;
	}

	void NewArray(int xmax, int yMax){
     	array = new T [xmax * yMax];
		xm = xmax;
		ym = yMax;
		CleanArray(array);
	}

private:	
	T *array;	//T *array
    int xm = 0;
	int ym = 0;
	int xy = 0;
};


