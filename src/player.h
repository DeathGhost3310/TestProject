#ifndef PLAYER_H
#define PLAYER_H

#include "header.h"
#include "Coord.h"
#include "inventory.h"

class Map;

class Unit
{
public:
    Unit(char value) :m_value(value) {}
    virtual ~Unit() {}
    char getValue() {return m_value;} ;
protected:
    char m_value;
    std::shared_ptr<Inventory> m_inventory;
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

///todo не наследовать, инкапсулировать
class Player : public Unit, public UnitCoord, public Inventory
{
public:
    
    Player(char value, Coord cord);
    ~Player();
    bool checkPlayer();
    Coord getCord() { return m_cord; };
    
    void move(KeyMove);
    void setMap(std::shared_ptr<Map> map);
private:
      
    std::weak_ptr<Map> m_map;

};


#endif