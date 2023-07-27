#include "bot.h"
#include <iostream>
#include "Map.h"
#include "player.h"




void Bot::moveToPlayer(Player* player)
{
    Coord cord = m_cord;
    Coord pCord = player->getCord();
    
    if (pCord.y < cord.y) { cord.y--; }
    if(pCord.y > cord.y)
    {cord.y++;}else if(pCord.y == cord.y){
        if(pCord.x < cord.x){cord.x--;}
        if(pCord.x > cord.x){cord.x++;}
    }                   
        
    /*auto dir = pCord - cord;
    dir = dir.getOne();
    cord += dir;*/
    

    m_map->move(m_cord,cord);
    
    m_cord = cord;
   
}
