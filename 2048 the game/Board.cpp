#include "Board.h"
#include<random>
#include<chrono>

typedef std::mt19937 rng_type;

int randomize_tile()
{	
	static std::uniform_int_distribution<rng_type::result_type> udist(1, 2);
	static rng_type rng(std::chrono::steady_clock::now().time_since_epoch().count());

	rng_type::result_type random_number = udist(rng);
	return random_number;
}

Board::Board():game_over(false),mWin(false)
{
	for (size_t i = 0; i < max; i++)
	{
		for (size_t j = 0; j < max; j++)
		{
			positions[i][j] = Tile(-1, i, j);
		}
	}
}

Board::~Board()
{
}

void Board::generateTile()
{
	Position pos = randomizePosition();
	positions[pos.x][pos.y].setValue(randomize_tile() << 1);
}

void Board::win()
{
	mWin = true;
	game_over = true;
}

void Board::lose()
{
	mWin = false;
	game_over = true;
}


Position Board::randomizePosition()
{
	static std::uniform_int_distribution<rng_type::result_type> udist(0, 3);
	static rng_type rng(std::chrono::steady_clock::now().time_since_epoch().count());
	Position pos = { udist(rng), udist(rng)};
	while (positions[pos.x][pos.y].getValue() != -1 )
	{
		pos.x = udist(rng);
		pos.y = udist(rng);
	}
	return pos;
}

constexpr bool Board::mergeSubOperation(int i, int j, int i1, int j1)
{
	
	if (positions[i][j].getValue() == 2048 || positions[i1][j1].getValue() == 2048)
	{
		win();
	}
	return true;
}

bool Board::onLeftArrowPressed(bool execute)
{
	bool mergePossible = false;
	Actions act;
	for (size_t i = 0; i < max; i++)
		for (size_t j = 1; j < max; j++)
		{
			Tile::isMergePossible(positions[i][j - 1], positions[i][j], act);
			if (act != Actions::None)
			{
				mergePossible = true;
				if (execute)
				{
					Tile::merge(positions[i][j - 1], positions[i][j]);
					mergeSubOperation(i, j, i, j - 1);
				}
					
			}
		}
	return mergePossible;
}

bool Board::onRightArrowPressed(bool execute)
{
	bool mergePossible = false;
	Actions act;
	for (size_t i = 0; i < max; i++)
		for (int j = max - 2; j >= 0; j--)
		{
			Tile::isMergePossible(positions[i][j + 1], positions[i][j], act);
			if (act != Actions::None)
			{
				mergePossible = true;
				if (execute)
				{
					Tile::merge(positions[i][j + 1], positions[i][j]);
					mergeSubOperation(i, j, i, j + 1);
				}
					
			}
		}

	return mergePossible;
}

bool Board::onUpArrowPressed(bool execute)
{
	bool mergePossible = false;
	Actions act;
	for (size_t i = 0; i < max; i++)
		for (size_t j = 1; j < max; j++)
		{
			Tile::isMergePossible(positions[j - 1][i], positions[j][i], act);
			if (act != Actions::None)
			{
				mergePossible = true;
				if (execute)
				{
					Tile::merge(positions[j-1][i], positions[j][i]);
					mergeSubOperation(i, j, j - 1, i);
				}
					
			}
		}
	return mergePossible;
}

bool Board::onDownArrowPressed(bool execute)
{
	bool mergePossible = false;
	Actions act;
	for (size_t i = 0; i < max; i++)
		for (int j = max - 2; j >= 0; j--)
		{
			Tile::isMergePossible(positions[j + 1][i], positions[j][i], act);
			if (act != Actions::None)
			{
				mergePossible = true;
				if (execute)
				{
					Tile::merge(positions[j + 1][i], positions[j][i]);
					mergeSubOperation(i, j, j + 1, i);
				}
					
			}
		}
			
	return mergePossible;
}
