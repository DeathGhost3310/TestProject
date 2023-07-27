#include "item.h"

#include <memory>
#include <string>

#include "console.h"
#include "Map.h"
#include "player.h"

Item::Item(std::string name , std::string description , int quality, ItemType itype)
	:m_name(name) , m_description(description) , 
	m_itemType(itype)
{
	
	
}

Item::~Item()
{
}


std::string Item::getString() {
	return  m_name;
}

std::string Item::getDiscriptionStr() {
	return m_description;
}

bool Item::useItem()
{
	if (m_useItem)
	{
		return m_useItem();
	}
	return false;
}

//void Item::bomb() {
//	
//	std::shared_ptr<Unit> boom_value(new Unit('-'));
//	if (m_quality > 0 && timer == 1) {
//		m_quality--;
//		timer = 6;	
//	}
//	Coord cd_cord;
//	std::shared_ptr<Map> t_map = m_map;
//	if (timer == 6) {
//		cd_cord = player->getCord();
//		m_map->setValue(cd_cord, m_value);
//		
//	}
//	
//	if (timer == 3) {
//		m_map->setValue(cd_cord, boom_value);
//		cd_cord.x++;
//		m_map->setValue(cd_cord, boom_value);
//		cd_cord.x = +2;
//		m_map->setValue(cd_cord, boom_value);
//		cd_cord.x--;
//		cd_cord.y++;
//		m_map->setValue(cd_cord, boom_value);
//		cd_cord.y = -2;
//		m_map->setValue(cd_cord, boom_value);
//		//timer = 1;
//	}
//	if (timer == 2) {
//		//Sleep(1000);
//       m_map = t_map;
//		Sleep(1000);
//		timer = 0;
//		delete t_map;
//		timer == 0;
//	}
//	if (timer != 0) { timer--; }
//}

void Item::setUseItem(const std::function<bool()>& useItem)
{
	m_useItem = useItem;
}