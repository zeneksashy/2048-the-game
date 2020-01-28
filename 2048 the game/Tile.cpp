#include "Tile.h"


Tile::Tile(int value, int x, int y)
{
	setValue(value);
	position = { x,y };
}

Tile::Tile(int value, Position pos): position(pos)
{
	setValue(value);
}

Tile::Tile():Tile(-1,-1,-1)
{
}

Tile::~Tile()
{
}

bool Tile::merge(Tile & t1, Tile & t2)
{
	Actions action;
	isMergePossible(t1, t2, action);
	switch (action)
	{
	case Actions::Merge:
		t1.value <<= 1;
		t2.value = -1;
		return true;
	case Actions::Move:
		t1.value = t2.value;
		t2.value = -1;
		return true;
	case Actions::None:
		return false;
	default:
		throw std::logic_error("Some case not handled");
		break;
	}

}

constexpr void Tile::isMergePossible(Tile & t1, Tile & t2, Actions & action)
{
	if (t1.value == -1 && t2.value == -1)
	{
		action = Actions::None;
		return;
	}
	if (t1.value == -1 && t2.value != -1)
	{
		action = Actions::Move;
		return;
	}
	if (t1.value != -1 && t2.value == -1)
	{
		action = Actions::None;
		return;
	}
	if (t1.value != t2.value)
	{
		action = Actions::None;
		return;
	}
	if (t1.value == t2.value)
	{
		action = Actions::Merge;
		return;
	}
	throw std::logic_error("Some case not handled");
}


void Tile::setValue(short val)
{
	if (val <= max_value)
		this->value = val;
}
