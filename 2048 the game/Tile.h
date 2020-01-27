#pragma once
#include "includes.h"

enum Borders
{
	Left, Right, UP, DOWN
};

struct Position
{
	int x;
	int y;
	constexpr bool operator == (const Position & other)
	{
		return other.x == x && other.y == y;
	}
	constexpr bool operator != (const Position & other)
	{
		return other.x != x && other.y != y;
	}
	constexpr bool isAbove(const Position & other)
	{
		return y - other.y == 1;
	}
	constexpr bool isUnder(const Position & other)
	{
		return other.y - y == 1;
	}
	constexpr bool isRight(const Position & other)
	{
		return x - other.x == 1;
	}
	constexpr bool isLeft(const Position & other)
	{
		return other.x - x == 1;
	}
	constexpr bool isOnBorder(const Borders & border)
	{
		switch (border)
		{
		case Left:
			return x == 0;
		case Right:
			return x == 3;
		case UP:
			return y == 3;
		case DOWN:
			return y == 0;
		default:
			return false;
		}
	}
};

class Tile
{
public:
	Tile(int value,int x, int y);
	Tile(int value, Position pos);
	Tile();
	~Tile();
	static bool merge(Tile &dest, Tile & source);
	static const int max_value = 2048;
	constexpr int getValue() { return value; }
private:

	void setValue(short val); // and width
	Position position;
	int value;
};

