#pragma once
#include "Tile.h"



class Board
{
public:
	Board();
	~Board();
	void generateTile();
	const int max_size = 16;
	virtual void win() = 0;
	virtual void lose() = 0;
	virtual void draw() = 0;
	bool onLeftArrowPressed();
	bool onRightArrowPressed();
	bool onUpArrowPressed();
	bool onDownArrowPressed();
	Position randomizePosition();
	constexpr bool isGameOver() { return game_over; }

protected:
	static const int max = 4;
	Tile positions[max][max];
	bool available[max][max];
private:
	bool checkAvailable();
	bool game_over;
	constexpr bool mergeSubOperation(int i,int j,int i1, int j1);
};

