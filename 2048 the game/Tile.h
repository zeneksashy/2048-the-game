#pragma once
#include "includes.h"


enum class Actions
{
	Merge, Move, None
};
struct Position
{
	int x;
	int y;
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

