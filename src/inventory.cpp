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

void Inventory::saveFile()
{
    //r, w, a, w+, ra+, wb

    const char* text = "aaaaaaaaaaaaaaaaa";

    FILE* file = fopen("file.txt", "w");
    fwrite(text, sizeof(text[0]), strlen(text), file);
    fclose(file);

    const int size = 10;
    char* c = new char [size];
    FILE* file = fopen("file.txt", "r");
    fread(c, sizeof(char), size, file);
    std::cout << c;
    fclose(file);
    delete c;



}

void Inventory::saveFstream() {
    std::ofstream save;
    save.open("FstreamSave.txt");
    if (save.is_open()) {
        int i = 0;
        for (auto item : m_items) {       
            save << item->getString() << " " << m_quality[i] << " ";
            i++;
        }
    }
    save.close();

    loadFstream("FstreamSave.txt");
}


void Inventory::loadFstream(const std::string& fileName)
{
    try
    {
        std::ifstream inventory_load;
        inventory_load.open(fileName);
        if (inventory_load.is_open()) {
            int i = 0;
            while (!inventory_load.eof())
            {
                std::string name;
                inventory_load >> name;

                std::string number;
                inventory_load >> number;
                int num = atoi(number.c_str());

            }
        }
        else
        {
            throw "can`t open";
        }
        inventory_load.close();
    }
    catch (std::runtime_error& err)
    {
        std::cout << " error ";

    }
    catch (const char* name)
    {
        std::cout << " error " << name;
    }
    catch (const std::string& name)
    {
        std::cout << " error " << name;
    }
    catch (...)
    {
        std::cout << " error " ;

    }
}

void Inventory::loadFstream(std::vector<std::shared_ptr<Item>>& item, std::vector<int>& quality) {
    m_items = item;
    m_quality = quality;

    std::ifstream load;
    load.open("FstreamSave.txt");
    if (load.is_open()) {
        int i = 0;
        for (auto item : m_items) {
            i++;
        }
    }
    load.close();

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
