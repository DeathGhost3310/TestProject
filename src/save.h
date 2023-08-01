#ifndef SAVE_H
#define SAVE_H

#include "console.h"
#include "controller.h"
#include "header.h"
#include "player.h"

#include <fstream>
#include <string>

class Save {
public:
	void saveMenu();
	void fstream_save();
	void saveMenuMove(KeyMove key);
	void setPlayer(Player* player);
	std::string saveInStr();
private:
	bool menuJob = false;
	int m_select = 1;
	Player* m_player = nullptr;
};
#endif