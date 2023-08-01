#ifndef INVENTORY_H
#define INVENTORY_H
#include "header.h"
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <fstream>


class Item;
class Map;


//FILE
//fstream
//winapi


class Inventory
{
public:
    Inventory(int size_inventory);
    Inventory();
    ~Inventory();
    void inventoryMove(KeyMove key);
    std::string getInventoryString();
    void pushitem(std::shared_ptr<Item> item,int quality);

    void saveFile();
   

    void saveFstream();
    void loadFstream(std::vector<std::shared_ptr<Item>> item,std::vector<int> quality);
    
    void saveWinapi();
   

private:
    int item_num = 0;
    int inventory_size;
    int itemQuality = 0;

protected:
    std::vector<std::shared_ptr<Item>> m_items;
    std::vector<int> m_quality;


    
};
#endif