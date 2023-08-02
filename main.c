#include <stdio.h>

char* memory = malloc(10000);

int* vector = NULL;
int count = 0;
int reserve = 0;

int push_back(int value)
{
	
    int* t_vector = vector;
	
	count++;
	vector = malloc((sizeof(int) * count));
	for(int i = 0;i < count - 1;i++){
       vector[i] = t_vector[i];
	}
    
	if(t_vector != NULL) {
		free(t_vector);
	}
	vector[count - 1] = value;
	//calloc(_Count, sizeof(int))
	//free(vector);
  /// ...
   
}

int push_back2(int value)
{
	if(count = reserve) {
		int* t_vector = vector;
		reserve = count * 2;
		vector = malloc((sizeof(int) * reserve));
		for(int i = 0;i < count - 1;i++){
			vector[i] = t_vector[i];
		}
		if(t_vector != NULL) {
			free(t_vector);
		}

	}

	count++;
	vector[count - 1] = value;
}

int pop_back()
{
	count--;
    
}

int getValue(int index)
{
	return vector[index];
}


int main()
{
	printf("hello");
    
	for(int i = 0; i < 10; ++i)
	{
		push_back(i);
		printf("value = %d %s %d %f", getValue(i), "count = ", count);
	}
	
///*
	pop_back();
	

	for (size_t i = 0; i < 9; i++)
	{
		int value = getValue(i);
		//assert(getValue(i) == i);
		printf("num %d \n", value);
	}
	printf("hello3");
	

//*/
	return 0;
}
