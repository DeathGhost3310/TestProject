#ifndef INVENTORY_H
#define INVENTORY_H
#include "header.h"
#include <string>
#include <memory>
#include <vector>
#include <map>



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
    void pushitem(std::shared_ptr<Item> item);

    void saveFile();
    void loadFile();

    void saveFstream();
    void loadFstream();
    
    void saveWinapi();
    void loadWinapi();

private:
    int item_num = 0;
    int inventory_size;
    int itemQuality = 0;

protected:
    std::vector<std::shared_ptr<Item>> m_items;



    
};
#endif