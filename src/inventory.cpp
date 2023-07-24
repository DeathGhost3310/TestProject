#include "inventory.h"
#include "item.h"



Inventory::Inventory(/* args */)
{

}
Inventory::~Inventory()
{

}

std::string Inventory::getInventoryString()
{
    std::string invString = "Inventory:\n-------------\n";

    for (auto& item : m_items)
    {
        // invString += ...item->getstr()
    }
    

    return invString;
}
