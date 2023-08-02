#include <stdio.h>


int* vector = NULL;
int count = 0;
int reserve = 0;

int push_back(int value)
{
	
    int* t_vector = malloc(sizeof(vector));
	t_vector = vector;
    //free(vector);
	vector = malloc((sizeof(int) * count));
	for(int i = 0;i < count;i++){
       vector[i] = t_vector[i];
	}
	free(t_vector);
	vector[count] = value;
	//calloc(_Count, sizeof(int))
	//free(vector);
  /// ...
  count++; 
}

int pop_back()
{
	count--;
    int* t_vector = malloc(sizeof(vector));
	t_vector = vector;
    //free(vector);
	vector = malloc(sizeof(int) * count);
	for(int i = 0;i < count;i++){
       vector[i] = t_vector[i];
	}
	free(t_vector);
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
		printf(getValue(i));
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
