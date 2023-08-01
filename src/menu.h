#ifndef MENU_H
#define MENU_H

#include "header.h"
#include "controller.h"
#include "console.h"
#include "controller.h"
#include "item.h"

#include <string>
#include <memory>
#include <fstream>

class Menu {
public:
	std::string loadInStr();
	void load_menu();
	void loadfstream();
	bool main_menu();
	void start();
	void exit();
	void menuMove(KeyMove key);
	std::string getMenuString();
private:
	int m_select = 1;
	bool start_game = false;
	bool menu_job = true;
	bool load_job = false;
};

#endif