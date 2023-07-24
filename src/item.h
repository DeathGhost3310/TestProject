#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{

public:
    Item(/* name , descroption */);
    ~Item();
    // string getString()
private:
    std::string m_name;
    std::string m_description;
    
};



#endif