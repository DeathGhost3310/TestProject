#ifndef INVENTORY_H
#define INVENTORY_H
#include "header.h"
#include <string>
#include <memory>
#include <vector>
#include <map>
class Item;
class Map;
class Inventory
{
public:
    Inventory(int size_inventory);
    Inventory();
    ~Inventory();
    void setMapI(Map* map);
    void inventoryMove(KeyMove key);
    std::string getInventoryString();
    void pushitem(std::shared_ptr<Item> item);
private:
    int item_num = 0;
    int inventory_size;
    int itemQuality = 0;
    Map* i_map = nullptr;
    //std::vector<std::shared_ptr<Item>> m_items;
    //std::map<int, int,std::shared_ptr<Item>> inventory;

protected:
    std::vector<std::shared_ptr<Item>> m_items;
};
#endif