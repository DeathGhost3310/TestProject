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
	void setPlayer(std::shared_ptr<Player> player);
	std::string saveInStr();
private:
	bool menuJob = false;
	int m_select = 1;
	std::weak_ptr<Player>  m_player;
};
#endif