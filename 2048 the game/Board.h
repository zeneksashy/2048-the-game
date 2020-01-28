#pragma once
#include "Tile.h"



class Board
{
public:
	Board();
	~Board();
	void generateTile();
	const int max_size = 16;
	virtual void win();
	virtual void lose();
	virtual void draw() = 0;
	virtual void showMessage(const std::string & msg) = 0;
	bool onLeftArrowPressed(bool execute = true);
	bool onRightArrowPressed(bool execute = true);
	bool onUpArrowPressed(bool execute = true);
	bool onDownArrowPressed(bool execute = true);
	Position randomizePosition();
	constexpr bool isGameOver() { return game_over; }
	constexpr bool hasWin() { return mWin; }
protected:
	static const int max = 4;
	Tile positions[max][max];
	bool game_over;

private:
	bool mWin;
	constexpr bool mergeSubOperation(int i,int j,int i1, int j1);
};

