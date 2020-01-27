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
	if (t1.value == -1 && t2.value == -1)
	{
		return false;
	}
	if (t1.value == -1 && t2.value != -1)
	{
		t1.value = t2.value;
		t2.value = -1;
		return true;
	}
	if (t1.value != -1 && t2.value == -1)
	{
		return false;
	}
	if (t1.value != t2.value)
	{
		return false;
	}
	if (t1.value == t2.value)
	{
		t1.value <<= 1;
		t2.value = -1;
		return true;
	}
	throw std::logic_error("Some case not handled");

}

void Tile::setValue(short val)
{
	if (val != max_value)
		this->value = val;
}
