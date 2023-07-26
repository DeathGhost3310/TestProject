#ifndef INVENTORY_H
#define INVENTORY_H
#include "header.h"
#include <string>
#include <memory>
#include <vector>
#include <map>
class Item;
class Inventory
{
public:
    Inventory(int size_inventory);
    Inventory();
    ~Inventory();
    void inventoryMove(KeyMove key);
    std::string getInventoryString();
    void pushitem(std::shared_ptr<Item> item);
private:
    int item_num = 0;
    int inventory_size;
    int itemQuality = 0;
    std::vector<std::shared_ptr<Item>> m_items;
    //std::map<int, int,std::shared_ptr<Item>> inventory;
};



#endif