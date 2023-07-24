
#include <iostream>
#include <stdio.h>
#include <vector>

#include "console.h"
#include "Map.h"
#include "bot.h"
#include "player.h"
#include "controller.h"
#include "header.h"

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
	Map *map = new Map({16, 40});
	std::vector<std::shared_ptr<Bot>> bots;
	for(int i = 0 ; i < 2; ++i)
	{
		int rx = 5 + 2*i;
		int ry = 5 + 2*i;
		std::shared_ptr<Bot> bot = std::make_shared<Bot>('q', Coord{ rx, ry }, map);
		
		bots.push_back(bot);
		map->setValue({rx , ry},bot);
	}
	

	auto player = std::make_shared<Player>('@', Coord{ 0 ,0 });
	player->setMap(map);
	map->setValue({0 , 0}, player);

 	Controller contr;
	Console console;

	std::string mapString;
	mapString = map->getMapString();
	console.mapPrint(mapString);

	KeyMove key = KeyMove::none;// = contr.getChar();

	while (key != KeyMove::escape)
	{
		key =  contr.getChar();
		if (key != KeyMove::none)
		{
			player->move(key);

			for (auto& bot : bots)
			{
				bot->moveToPlayer(player.get());
			}
			mapString = map->getMapString();
			console.mapPrint(mapString);
		}
	}
	

	return 0;
}