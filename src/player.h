#ifndef PLAYER_H
#define PLAYER_H

#include "header.h"
#include "Coord.h"

class Map;
class Unit
{
public:
    Unit(char value) :m_value(value) {}
    virtual ~Unit() {}
    char getValue() {return m_value;} ;
protected:
    char m_value;
};
class UnitCoord 
{
public:
    UnitCoord(Coord cord) :m_cord(cord) {
        
    }
    virtual ~UnitCoord() {}
    Coord getCord() { return m_cord; };
protected:
    Coord m_cord;
};

class Player : public Unit, public UnitCoord
{
public:
    Player(char value, Coord cord);
    ~Player();
        
    Coord getCord() { return m_cord; };
    
    void move(KeyMove);
    void setMap(Map* map);
private:
   
    
    Map *m_map = nullptr;
};


#endif