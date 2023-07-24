#include "Map.h"
#include <iostream>
#include "player.h"



Map::Map(Coord cdMax) :
  m_cdMax(cdMax)
{
};

Map::~Map()
{

	
}

std::string Map::getMapString()
{
	std::string mapStr;

	for (int i = 0; i < m_cdMax.x; i++)
	{
		for (int j = 0; j < m_cdMax.y; j++)
		{

			auto cd = Coord(i, j);

			if (m_array.find(cd) != m_array.end() && m_array[cd])
			{
				{
					mapStr.push_back(m_array[{i, j}]->getValue());
				}
			}
			else {
				mapStr.push_back(empty);
			}
		}

		mapStr.push_back('\n');

	}

	return mapStr;
}

char Map::getValue(Coord cord){
	if (m_array[cord])
   {
      return empty;
   }
    return m_array[cord]->getValue();
}

void Map::move(Coord start, Coord cdEnd ){
	setValue(cdEnd, m_array[start]);

	setValue(start, nullptr);
  
};

void Map::setValue(Coord cord, std::shared_ptr<Unit> unit){
	m_array[cord] =  unit;
}



