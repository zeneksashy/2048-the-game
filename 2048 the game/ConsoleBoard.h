#pragma once
#include "Board.h"

class ConsoleBoard :
	public Board
{
public:
	ConsoleBoard();
	~ConsoleBoard();

	// Inherited via Board
	virtual void draw() override;
	virtual void showMessage(const std::string & message) override;
};

