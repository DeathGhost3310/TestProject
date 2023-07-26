#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{

public:
    Item(std::string name, std::string description , int quality);
    ~Item();
    //void bomb();
    std::string getString();
    std::string getDiscriptionStr();
private:
    std::string m_name;
    std::string m_description;
    int m_quality;
};



#endif