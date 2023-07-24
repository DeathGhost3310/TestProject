#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <memory>
#include <vector>

class Item;
class Inventory
{
public:
    Inventory(/* args */);
    ~Inventory();
    std::string getInventoryString();
    // pushitem()
private:
    std::vector<std::shared_ptr<Item>> m_items;

};



#endif