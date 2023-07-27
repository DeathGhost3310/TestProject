#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <memory>
//#include "Map.h"
class Unit;
class Map;
class Player;
class Item
{

public:
    Item(std::string name, std::string description , int quality);
    ~Item();
    void useItem();
    void bomb();
    void setPCoord(Player* p);
    void setMap(Map* map);
    std::string getString();
    std::string getDiscriptionStr();
private:
    std::string m_name;
    std::string m_description;
    int m_quality;
    int timer = 1;
    Map *m_map = nullptr;
    std::shared_ptr<Unit> m_value;
    Player* player = nullptr;
};



#endif