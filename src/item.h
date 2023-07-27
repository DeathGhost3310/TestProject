#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <memory>
#include <functional>

#include "Coord.h"
#include "item_type.h"

class Unit;
class Map;

class Item
{
public:
    Item(std::string name, std::string description , int quality , ItemType itype);
    ~Item();
    std::string getString();
    std::string getDiscriptionStr();
    bool useItem();
    void setUseItem(const std::function<bool()>& useItem);
private:
    std::string m_name;
    std::string m_description;
    ItemType m_itemType = ItemType::count;
    std::function<bool()> m_useItem;
};



#endif