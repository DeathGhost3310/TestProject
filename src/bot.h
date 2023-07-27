#ifndef BOT_H
#define BOT_H
#include "player.h"
#include "Map.h"

class Player;

class Bot : public Unit , public UnitCoord
{
public:
    Bot(char value ,Coord cord , std::shared_ptr<Map> map)
    : UnitCoord(cord),
      Unit(value),
        m_map(map)
    {
        int i = 0;
        i++;
    }
    ~Bot(){}

    void searchPlayer();
    void moveToPlayer(Player* player);
private:

    std::shared_ptr<Map> m_map = nullptr;
};





#endif