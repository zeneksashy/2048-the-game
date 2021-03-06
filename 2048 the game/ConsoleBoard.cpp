#include "ConsoleBoard.h"
#include<stdlib.h>
#include <iomanip>
#include<string>

ConsoleBoard::ConsoleBoard():Board()
{
}


ConsoleBoard::~ConsoleBoard()
{
}


void ConsoleBoard::draw()
{
	system("cls");
	for (size_t i = 0; i < max; i++)
	{
		std::cout << "---------------------\n";
		for (size_t j = 0; j < max; j++)
		{

			std::cout << '|' << std::setw(4);
			if (positions[i][j].getValue() > 0)
				std::cout << positions[i][j].getValue();
			else
				std::cout << "";
		}
		std::cout << "|\n";

	}
	std::cout << "---------------------\n";
}

void ConsoleBoard::showMessage(const std::string & message)
{
	std::cout << message << '\n';
}
