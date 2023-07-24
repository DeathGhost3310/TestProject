#pragma once
#ifndef COORD_H
#define COORD_H


class Coord
{
public:
	Coord();
	Coord(int x, int y);

	friend Coord operator+(const Coord& left, const Coord& right);
	friend Coord operator-(const Coord& left, const Coord& right);

	friend bool operator<(const Coord& left, const Coord& right);

	int x;
	int y;
};



#endif
