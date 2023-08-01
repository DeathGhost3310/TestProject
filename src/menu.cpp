#include "menu.h"
void Menu::start() {
	menu_job = false;
	start_game = true;
}
void Menu::loadfstream() {
	std::ifstream load;
	load.open("FstreamSave.txt");
	if (load.is_open()) {
	
	}
	load.close();
}
void Menu::exit() {
	menu_job = false;
	start_game = false;	
}
bool Menu::main_menu() {
	Console console;
	Controller contr;
	KeyMove key;
	console.mapPrint(getMenuString());
	while (menu_job) {
		key = contr.getChar();
		menuMove(key);
		console.mapPrint(getMenuString());
		
	}
	console.clear();
	return start_game;
}
void Menu::menuMove(KeyMove key) {
	switch (key) {
	case KeyMove::up:
		if (m_select > 1) {
			m_select--;
		}
		break;
	case KeyMove::down:
			if (m_select < 3 && !load_job) {
				m_select++;
			}		
			if (m_select < 4 && load_job) {
				m_select++;
			}		
		break;
	case KeyMove::select:
		if (!load_job) {
			if (m_select == 1) {
				start();
			}
			if (m_select == 2) {
				m_select = 1;
				load_menu();
			}
			if (m_select == 3) {
				exit();
			}
		}
		if (load_job) {
			if (m_select == 1) {
				loadfstream();
			}
			if (m_select == 2) {
			
			}
			if (m_select == 3) {
			
			}
			if (m_select == 4) {
				m_select = 1;
			    load_job = false;
			}
		}
		break;
	default:
		break;
	}
}
void Menu::load_menu() {
	load_job = true;
	Console console;
	Controller contr;
	bool load_menu_job = true;
	KeyMove key;
	console.mapPrint(loadInStr());
	while (load_job) {
		key = contr.getChar();
		menuMove(key);
		console.mapPrint(loadInStr());
	}
}
std::string Menu::loadInStr() {
	
	std::string loadStr;
	
	loadStr += "#      ###     #    ####\n#     #   #   # #   #   #\n#     #   #  #   #  #   #\n#     #   #  #####  #   #\n#####  ###  #     # ####\n";
	loadStr.push_back('\n');
	if (m_select != 1) { loadStr += "  "; }
	if (m_select == 1) { loadStr += " >"; }
	loadStr += "fstream\n";
	if (m_select != 2) { loadStr += "  "; }
	if (m_select == 2) { loadStr += " >"; }
	loadStr += "winapi\n";
	if (m_select != 3) { loadStr += "  "; }
	if (m_select == 3) { loadStr += " >"; }
	loadStr += "FILE\n";
	if (m_select != 4) { loadStr += "  "; }
	if (m_select == 4) { loadStr += " >"; }
	loadStr += "back";
	return loadStr;
}
std::string Menu::getMenuString() {
	
	std::string menuStr;
	
	menuStr += "##### ####  #### #####   ####    ####   ###    #  ####  #### #####\n  #   #    #       #     #   #  #   #  #   #   #  #    #       #\n  #   #### #####   #     ####   #      #   #   #  #### #       #\n  #   #        #   #     #      #      #   #   #  #    #       #\n  #   #### ####    #     #      #       ###  ##   ####  ####   #\n";
	menuStr.push_back('\n');
	if (m_select != 1) { menuStr += "  "; }
	if (m_select == 1) { menuStr += " >"; }
	menuStr += "start\n";
	if (m_select != 2) { menuStr += "  "; }
	if (m_select == 2) { menuStr += " >"; }
	menuStr += "load\n";
	if (m_select != 3) { menuStr += "  "; }
	if (m_select == 3) { menuStr += " >"; }
	menuStr += "exit\n";
	
	return menuStr;
}