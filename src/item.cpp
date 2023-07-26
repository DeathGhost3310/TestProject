#include "item.h"

Item::Item(std::string name , std::string description , int quality)
	:m_name(name) , m_description(description) , m_quality(quality)
{
	
}
Item::~Item()
{
}
std::string Item::getString() {
	return std::to_string(m_quality) + " " + m_name;
}
std::string Item::getDiscriptionStr() {
	return m_description;
}
/*void Item::bomb() {
	if (m_name != "bomb") {
		m_name = "bomb";
	}
	m_quality++;
*///}