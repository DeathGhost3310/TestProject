#include "player.h"
#include "Map.h"
#include "inventory.h"
#include "item.h"
Player::Player(char value, Coord cord):
    UnitCoord(cord),
    Unit(value),
    Inventory(15)
{   
    std::shared_ptr<Item> dash = std::make_shared<Item>("dash", "=====", 12);
    std::shared_ptr<Item> bomb = std::make_shared<Item>("bomb","------" , 10);
    pushitem(bomb);
    pushitem(dash);
}

Player::~Player()
{

}



bool Player::checkPlayer() {
    if (m_map->getValue(getCord()) != m_value) {
        return false;
    }
    return true;
}
void Player::move(KeyMove key){
    Coord newCord = m_cord;
    Coord dc = { 0,0 };
    bool checkCord = true;
    int x_max = m_map->getCordX();
    int y_max = m_map->getCordY();
    switch (key)
    {
    case KeyMove::up:
        if (newCord.x - 1 > 0) {
            dc = { -1, 0 };
            break;
        }
        checkCord = false;
        break;
    case KeyMove::down:
        if (newCord.x + 1 < x_max) {
            dc = { 1, 0 };
            break;
        }
        checkCord = false;
        break;
    case KeyMove::left:
        if (newCord.y > 0) {
            dc = { 0, -1 };
            break;
        }
        checkCord = false;
        break;
    case KeyMove::right:
        if (newCord.y < y_max) {
            dc = { 0, 1 };
            break;
        }
        checkCord = false;
        break;
    default:
        break;
    }
    if (checkCord) {
        newCord = newCord + dc;
        m_map->move(m_cord, newCord);
        m_cord = newCord;
    }
};

void Player::setMap(Map* map)
{
    m_map = map;
}