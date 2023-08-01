#include <stdio.h>


int* vector = NULL;
int count = 0;
int reserve = 0;

int push_back(int value)
{
	vector = malloc(sizeof(int));
	vector[count] = value;
	//calloc(_Count, sizeof(int))
	//free(vector);
  /// ... 
}

int pop_back()
{
  ///...
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
	}
	

	pop_back();
	

	for (size_t i = 0; i < 9; i++)
	{
		int value = getValue(i);
		//assert(getValue(i) == i);
		printf("num %d \n", value);
	}
	printf("hello3");
	


	return 0;
}