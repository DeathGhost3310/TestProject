#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
//#include <Map>

using namespace std;

void map(int x, int y) {
    cout << "\033[2J\033[1 ; 1H";
    int sj, si, key;
    bool cord[16][40];
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 40; j++) {
            cord[i][j] = false;
        }
    }
    cord[x][y] = true;
    std::string smap;
    smap.reserve(16*40 + y);

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 40; j++) {
            if (cord[i][j] == true) {
                smap.push_back('&');
            }
            else
            {
                smap.push_back('*');
            }
        }
        smap.push_back('\n');
    }

    printf_s(smap.c_str());

};

//struct Coord
//{
//    int x, y;
//
//};
//class Bot
//{
//public:
//    Bot();
//    ~Bot();
//
//private:
//
//};
//
//class Map
//{
//public:
//    Map();
//    ~Map();
//
//    void print();
//    void move(int x, int y);
//
//private:
//    int m_xMax;
//    int m_yMax;
//    std::map < Coord, Bot> m_map;
//    Bot m_mainBot;
//};




int main() {
    int x = 1;
    int y = 1;
    char key;
    map(x, y);
    while (true) {
        key = _getch();

        if (('w' == key || key == 72) && x > 0) {
            x--;
            map(x, y);
        }
        if (('s' == key || key == 80)&& x < 15) {
            x++;
            map(x, y);
        }
        if (('d' == key || key == 77) && y < 39) {
            y++;
            map(x, y);
        }
        if (('a' == key || key == 75)&& y > 0) {
            y--;
            map(x, y);
        }
    }
    return 0;
}