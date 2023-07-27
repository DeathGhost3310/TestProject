
#include <iostream>
#include <stdio.h>
#include <vector>

#include "console.h"
#include "Map.h"
#include "bot.h"
#include "player.h"
#include "controller.h"
#include "header.h"
#include "item.h"

/// <summary>
/// проверка выхода за пределы массива
/// проверка чтобы боты не затирали друг лруга
/// что должно происходить когда догнал
/// Coord -> const Coord&
/// 
/// </summary>
/// <returns></returns>

int main()
{
	std::shared_ptr<bool> openInventory(new bool(true));
	std::shared_ptr<Map> map(new Map({ 16, 40 }));
	std::vector<std::shared_ptr<Bot>> bots;
	for (int i = 0; i < 2; ++i)
	{
		int rx = 5 + 2 * i;
		int ry = 5 + 2 * i;
		std::shared_ptr<Bot> bot = std::make_shared<Bot>('q', Coord{ rx, ry }, map);

		bots.push_back(bot);
		map->setValue({ rx , ry }, bot);
	}
	

	auto player = std::make_shared<Player>('@', Coord{ 0 ,0 });
	player->setMap(map);

	std::shared_ptr<Item> dash = std::make_shared<Item>("dash", "Dash 2 symbol", 12, ItemType::dash);
	std::shared_ptr<Item> bomb = std::make_shared<Item>("bomb", "Xz Boom", 10, ItemType::bomb);
	player->pushitem(bomb);
	player->pushitem(dash);


	

	auto lam = [map, player]() -> bool
	{
		std::cout << "boom";
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

		return true;
	};

	bomb->setUseItem(
		lam
	
	);

	map->setValue({ 0 , 0 }, player);
	
	Controller contr;
	Console console;

	std::string mapString;
	mapString = map->getMapString();
	console.mapPrint(mapString);

	KeyMove key = KeyMove::none;// = contr.getChar();
	bool startGame = true;
	while (startGame)
	{
		//if (key != KeyMove::escape) {
			//startGame = false;
		//}
		key = contr.getChar();
		if (key != KeyMove::none)
		{
			if (key != KeyMove::open_inventory) {
				player->move(key);

				for (auto& bot : bots)
				{
					bot->moveToPlayer(player.get());
				}
                 mapString = map->getMapString();
				console.mapPrint(mapString);
				
			}
			if (key == KeyMove::open_inventory) {
				do{
					mapString = player->getInventoryString();
					console.mapPrint(mapString);
					key = contr.getChar();
					player->inventoryMove(key);
				} while (key != KeyMove::open_inventory);
				mapString = map->getMapString();
				console.mapPrint(mapString);

			}

		}


	}
		//if (player->checkPlayer()) {
			//startGame = false;
		//}



		return 0;
}
