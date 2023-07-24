#include "player.h"
#include "Map.h"

Player::Player(char value, Coord cord):
    UnitCoord(cord),
    Unit(value)
{
   
}

Player::~Player()
{

}



 
void Player::move(KeyMove key){
    Coord newCord = m_cord;
    Coord dc = { 0,0 };
    switch (key)
    {
    case KeyMove::up:
        dc = { -1, 0 };
        break;
    case KeyMove::down:
        dc = { 1, 0 };
        break;
    case KeyMove::left:
        dc = { 0, -1 };
        break;
    case KeyMove::right:
        dc = { 0, 1 };
        break;
    default:
        break;
    }
     newCord = newCord + dc;
     m_map->move(m_cord,newCord);
     m_cord = newCord;
    
};

void Player::setMap(Map* map)
{
    m_map = map;
}