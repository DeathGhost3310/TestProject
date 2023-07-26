#include "inventory.h"
#include "item.h"
#include "header.h"

Inventory::Inventory(int size_inventory)
    :inventory_size(size_inventory)
{
  
}
Inventory::Inventory() :inventory_size(30){}
Inventory::~Inventory()
{

}
void Inventory::inventoryMove(KeyMove key) {
        if (itemQuality >= *item_num) { *item_num = 1; }
    switch (key) {
    case KeyMove::up:
        if (*item_num > 1) { *item_num -= 1; }
        break;
    case KeyMove::down:
        if (*item_num < itemQuality) { *item_num += 1; }
        break;
    default:
        break;
    }
    }

std::string Inventory::getInventoryString()
{
    std::string invString = "Inventory:\n-------------\n";
    for (int i = 0;i < inventory_size;i++) {
        for (auto& item : m_items) {
            if (i < itemQuality) {
                invString.push_back(' ');
                invString.push_back(' ');
                //if (*item_num == i) { invString.push_back('#'); }
                invString += item->getString();
                invString.push_back('\n');
                i++;
            }
        }
        invString.push_back('\n');
    }
    for (int i = 0;i < 60;i++) {
        invString.push_back('-');
    }
    invString.push_back('\n');
    
    return invString;
}
void Inventory::pushitem(std::shared_ptr<Item> item) {
    m_items.push_back(item);
    itemQuality++;
}
