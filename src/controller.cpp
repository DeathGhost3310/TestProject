#include "controller.h"
#include <conio.h>

KeyMove Controller::getChar(){ 
    char key = _getch();
    KeyMove keyMove = KeyMove::none;
    if (('w' == key || key == 72) ) { keyMove = KeyMove::up; }
    if (('s' == key || key == 80) ) { keyMove = KeyMove::down;  }
    if (('d' == key || key == 77) ) { keyMove = KeyMove::right; }
    if (('a' == key || key == 75) ) { keyMove = KeyMove::left;  }
    if ('i' == key) { keyMove = KeyMove::open_inventory; }
    if ('f' == key) { keyMove = KeyMove::use_item; }
    if ('e' == key) { keyMove = KeyMove::select; }
    if (27 == key) { keyMove = KeyMove::escape; }
    if ('o' == key) { keyMove = KeyMove::save_menu; }
    return keyMove;

}   