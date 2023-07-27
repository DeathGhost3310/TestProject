#include <iostream>;
#include "Coord.h"

Coord::Coord():
	x(0), y(0)
{}

Coord::Coord(int x, int y):
    x(x) , y(y)
{
}

Coord operator+(const Coord& left, const Coord& right) { return Coord(left.x + right.x, left.y + right.y); }

Coord operator-(const Coord& left, const Coord& right) { return Coord(left.x - right.x, left.y - right.y); }	

bool operator<(const Coord& left, const Coord& right)
{
	return 1000 * left.x + left.y < 1000 * right.x + right.y;
}
