#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <map>
#include <memory>
#include "Coord.h"


#include "player.h"
class Unit;

const char empty = '.';

class Map
{
public:
   
	Map(Coord cdMax);
	~Map();
	char getValue(Coord cord);
	void move(Coord start, Coord cdEnd);
	void setValue(Coord cord, std::shared_ptr<Unit> unit);
    /*int getXMax(){return m_xmax;};
    int getYMax(){return m_ymax;};*/
	
	std::string getMapString();

private:	
	Coord m_cdMax;
	std::map < Coord, std::shared_ptr<Unit>> m_array;
};

#endif
