#include "save.h"

void Save::setPlayer(Player* player) {
	m_player = player;
}

void Save::saveMenu() {
	menuJob = true;
	Console console;
	Controller contr;
	KeyMove key;
	console.mapPrint(saveInStr());
	while (menuJob) {
		key = contr.getChar();
		saveMenuMove(key);
		console.mapPrint(saveInStr());

	}
	console.clear();
	menuJob = false;
}
void Save::saveMenuMove(KeyMove key) {
	
	switch (key) {
	case KeyMove::up:
		if (m_select > 1) {
			m_select--;
		}
		break;
	case KeyMove::down:
		if (m_select < 4) {
			m_select++;
		}
		break;
	case KeyMove::select:

		if (m_select == 1) {
			fstream_save();
		}
		if (m_select == 2) {


		}
		if (m_select == 3) {

		}
		if (m_select == 4) {
			menuJob = false;
		}
		break;
	default:
		break;
	}
}
void Save::fstream_save() {
	m_player->saveFstream();
}
std::string Save::saveInStr() {
	std::string saveStr;
	saveStr += " ####    #    #   # #####\n#       # #   #   # #\n#####  #   #  #   # #####\n    #  #####   # #  #\n####  #     #  ###  #####\n";
	saveStr.push_back('\n');
	if (m_select != 1) { saveStr += "  "; }
	if (m_select == 1) { saveStr += " >"; }
	saveStr += "fstreamSave\n";
	if (m_select != 2) { saveStr += "  "; }
	if (m_select == 2) { saveStr += " >"; }
	saveStr += "FiLE\n";
	if (m_select != 3) { saveStr += "  "; }
	if (m_select == 3) { saveStr += " >"; }
	saveStr += "winapi\n";
	if (m_select != 4) { saveStr += "  "; }
	if (m_select == 4) { saveStr += " >"; }
	saveStr += "back";
	return saveStr;
}
