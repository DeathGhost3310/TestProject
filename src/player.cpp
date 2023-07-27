#include "player.h"
#include "Map.h"
#include "inventory.h"
#include "item.h"
Player::Player(char value, Coord cord):
    UnitCoord(cord),
    Unit(value),
    Inventory(15)
{   
    //std::shared_ptr<Item> dash = std::make_shared<Item>("dash", "Dash 2 symbol", 12);
    //std::shared_ptr<Item> bomb = std::make_shared<Item>("bomb","Xz Boom" , 10);
    //pushitem(bomb);
    //pushitem(dash);
    
}

Player::~Player()
{

}



bool Player::checkPlayer() {
    if (m_map.lock()->getValue(getCord()) != m_value) {
        return false;
    }
    return true;
}
void Player::move(KeyMove key){
    Coord newCord = m_cord;
    Coord dc = { 0,0 };
    bool checkCord = true;

    auto map = m_map.lock();

    int x_max = map->getCordX();
    int y_max = map->getCordY();
    
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
        
        std::shared_ptr<Map> map(m_map.lock());

        if (map) {
            map->move(m_cord, newCord);

            m_cord = newCord;
        }
    }
};

void Player::setMap(std::shared_ptr<Map> map)
{
    m_map = map;

    /*std::shared_ptr<Item> dash = std::make_shared<Item>("dash", "Dash 2 symbol", 12);
    std::shared_ptr<Item> bomb = std::make_shared<Item>("bomb", "Xz Boom", 10);
    pushitem(bomb);
    pushitem(dash);*/
}