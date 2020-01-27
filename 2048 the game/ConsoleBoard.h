#pragma once
#include "Board.h"

class ConsoleBoard :
	public Board
{
public:
	ConsoleBoard();
	~ConsoleBoard();

	// Inherited via Board
	virtual void win() override;
	virtual void lose() override;
	virtual void draw() override;
private:

};

