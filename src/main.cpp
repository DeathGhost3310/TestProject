
#include <iostream>
#include "Map2.h"

//указатели
//шаблоны
//delete delete[] удаление указателя удаление массива 

int main()
{

	Map<bool> map(5, 4);
    
	map.setValue(0, 0, true);

	map.setValue(0, 1, true);

	map.setValue(0, 3, true);

	map.setValue(5, 2, true);

	map.setValue(2, 0, false);

    
	std::cout << "0 0: " << map.getValue(0, 0) << std::endl;
	std::cout << "2 0: " << map.getValue(2, 0) << std::endl;
	
	//std::cout << "20 20: " << map.getValue(20, 20) << std::endl;
	map.print();

	Map<int> map2(20, 20);
	map2.setValue(25, 15, 45);	
    map2.print();
	return 0;
}