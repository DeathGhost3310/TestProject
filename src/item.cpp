#include "item.h"
#include <memory>
#include "Map.h"
#include "console.h"
#include <string>
#include "player.h"
#include <Windows.h>
Item::Item(std::string name , std::string description , int quality)
	:m_name(name) , m_description(description) , m_quality(quality)
{
	if (m_name == "bomb") {
		Unit m_value = '#';
		timer = 0;
	}
	
}
Item::~Item()
{
}
void Item::setMap(Map* map) {
	m_map = map;
}
void Item::setPCoord(Player* p) {
	player = p;
}
std::string Item::getString() {
	return std::to_string(m_quality) + " " + m_name;
}
std::string Item::getDiscriptionStr() {
	return m_description;
}
void Item::useItem() {
	if (m_name == "bomb") {
		bomb();
		return;
	}
	if (m_name == "bullet") {
	    //bullet();
		return;
	}
}
void Item::bomb() {
	
	std::shared_ptr<Unit> boom_value(new Unit('-'));
	if (m_quality > 0 && timer == 1) {
		m_quality--;
		timer = 6;	
	}
	Coord cd_cord;
	Map* t_map = m_map;
	if (timer == 6) {
		cd_cord = player->getCord();
		m_map->setValue(cd_cord, m_value);
		
	}
	
	if (timer == 3) {
		m_map->setValue(cd_cord, boom_value);
		cd_cord.x++;
		m_map->setValue(cd_cord, boom_value);
		cd_cord.x = +2;
		m_map->setValue(cd_cord, boom_value);
		cd_cord.x--;
		cd_cord.y++;
		m_map->setValue(cd_cord, boom_value);
		cd_cord.y = -2;
		m_map->setValue(cd_cord, boom_value);
		//timer = 1;
	}
	if (timer == 2) {
		//Sleep(1000);
       m_map = t_map;
		Sleep(1000);
		timer = 0;
		delete t_map;
		timer == 0;
	}
	if (timer != 0) { timer--; }
}