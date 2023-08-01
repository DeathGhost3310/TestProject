#include "inventory.h"
#include "item.h"
#include "header.h"
#include "Map.h"

Inventory::Inventory(int size_inventory)
    :inventory_size(size_inventory)
{
  
}

Inventory::Inventory() :inventory_size(30){}

Inventory::~Inventory()
{

}

void Inventory::inventoryMove(KeyMove key) {
    if (itemQuality >= item_num) { item_num = 0; }
    switch (key) {
    case KeyMove::up:
        if (itemQuality >= item_num) { item_num = 0; }
        if (item_num > 1) { item_num -= 1; }
        break;
    case KeyMove::down:
        if (item_num < itemQuality - 1 ) { item_num += 1; }
        break;
    case KeyMove::use_item:
        if (item_num < itemQuality ) { m_items[item_num]->useItem(); }
        if (item_num == 2) { saveFstream(); }
        break;
    default:
        break;
    }
    }
void Inventory::saveFstream() {
    std::ofstream save;
    save.open("FstreamSave.txt");
    if (save.is_open()) {
        int i = 0;
        for (auto item : m_items) {       
            save << item << " " << m_quality[i];
            i++;
        }
        }
}
void Inventory::loadFstream(std::vector<std::shared_ptr<Item>> item, std::vector<int> quality) {
    m_items = item;
    m_quality = quality;
}
std::string Inventory::getInventoryString()
{
    ///todo ��������� ���� ��������� ������
    std::string invString = "Inventory:\n-------------\n";
    for (int i = 0;i < inventory_size;i++) {
            if(i < m_items.size())
            {
                auto& item = m_items[i];
                if (i < itemQuality) 
                {
                    if (item_num == i) {
                        invString += (">"); 
                    }
                    else
                    {
                        invString += " ";
                    }
                    invString += item->getString();
                    invString.push_back('\n');
                   
                }
        }
        invString.push_back('\n');
    }
   
    invString += "------------------------------------------------";
    
    invString.push_back('\n');
    invString += m_items[item_num]->getDiscriptionStr();
    invString.push_back('\n');
    invString += " ";
    if (item_num == itemQuality) { invString.push_back('>'); }
    invString += "FstreamSave";
    invString.push_back('\n');
    return invString;
}

void Inventory::pushitem(std::shared_ptr<Item> item,int quality) {
    m_items.push_back(item);
    itemQuality++;
    m_quality.push_back(quality);
}
