#pragma once
#include "includes.h"

enum class Borders
{
	Left, Right, UP, DOWN
};

enum class Actions
{
	Merge, Move, None
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
		case Borders::Left:
			return x == 0;
		case Borders::Right:
			return x == 3;
		case Borders::UP:
			return y == 3;
		case Borders::DOWN:
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
	constexpr static void isMergePossible(Tile &dest, Tile & source, Actions & action);
	static const int max_value = 2048;
	constexpr int getValue() { return value; }
	void setValue(short val); 
private:


	Position position;
	int value;
};

