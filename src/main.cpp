#include <thread>
#include <iostream>
#include <stdio.h>
#include <vector>

#include "timer.h"
#include "console.h"
#include "Map.h"
#include "bot.h"
#include "player.h"
#include "controller.h"
#include "header.h"
#include "item.h"

/// <summary>
/// �������� ������ �� ������� �������
/// �������� ����� ���� �� �������� ���� �����
/// ��� ������ ����������� ����� ������
/// Coord -> const Coord&
/// 
/// </summary>
/// <returns></returns>

int main()
{
	std::shared_ptr<bool> openInventory(new bool(true));
	Timer& timer = Timer::createTimer();
	Controller contr;
	Console console;
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


	

	auto lam = [map, player, &timer, &console]() -> bool
	{
		
		std::cout << "boom";
		std::shared_ptr<Unit> bomb(new Unit('#'));
	    Coord cd_cord = player->getCord();
		map->setValue(cd_cord, bomb);
        
		auto l = [map, cd_cord, &console](){
            auto vec = {Coord{-1, 0}, Coord{1, 0},Coord{0 , 0} , Coord{0, 1}, Coord{0, -1} };
			std::shared_ptr<Unit> boom_value(new Unit('-'));
		    for(auto& c : vec ){
				map->setValue(cd_cord + c, boom_value);
			}
			console.mapPrint(map->getMapString());
			std::this_thread::sleep_for(std::chrono::seconds(1));
			
			for(auto& c : vec ){
				map->setValue(cd_cord + c, nullptr);
			}
			console.mapPrint(map->getMapString());
		};
		timer.subscribe(6, l);

		return true;
	};

	bomb->setUseItem(
		lam
	
	);

	map->setValue({ 0 , 0 }, player);
	
	

	std::string mapString;
	mapString = map->getMapString();
	console.mapPrint(mapString);

	KeyMove key = KeyMove::none;// = contr.getChar();
	bool startGame = true;
	while (startGame)
	{
		timer.timer();
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
