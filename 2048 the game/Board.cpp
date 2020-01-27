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

Board::Board():game_over(false)
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
	if (!checkAvailable())
	{
		game_over = true;
		lose();
	}

	Position pos = randomizePosition();
	auto new_tile = Tile(randomize_tile() << 1,pos);
	positions[pos.x][pos.y] = new_tile;
	available[pos.x][pos.y] = false;
}


Position Board::randomizePosition()
{
	static std::uniform_int_distribution<rng_type::result_type> udist(0, 3);
	static rng_type rng(std::chrono::steady_clock::now().time_since_epoch().count());
	Position pos = { udist(rng), udist(rng)};
	while (!available[pos.x][pos.y])
	{
		pos.x = udist(rng);
		pos.y = udist(rng);
	}
	return pos;
}

bool Board::checkAvailable()
{
	for (size_t i = 0; i < max; i++)
	{
		for (size_t j = 0; j < max; j++)
		{
			if (available[i][j])
				return true;
		}
	}
	return false;
}

constexpr bool Board::mergeSubOperation(int i, int j, int i1, int j1)
{
	available[i][j] = true;
	available[i1][j1] = false;
	if (positions[i][j].getValue() == 2048)
	{
		game_over = true;
		win();
	}
	return true;
}

bool Board::onLeftArrowPressed()
{
	bool mergePossible = false;
	for (size_t i = 0; i < max; i++)
		for (size_t j = 1; j < max; j++)
			if (Tile::merge(positions[i][j - 1], positions[i][j]))
				mergePossible = mergeSubOperation(i, j, i, j - 1);
	return mergePossible;
}

bool Board::onRightArrowPressed()
{
	bool mergePossible = false;
	for (size_t i = 0; i < max; i++)
		for (int j = max - 2; j >= 0; j--)
			if (Tile::merge(positions[i][j + 1], positions[i][j]))
				mergePossible = mergeSubOperation(i, j, i, j + 1);

	return mergePossible;
}

bool Board::onUpArrowPressed()
{
	bool mergePossible = false;
	for (size_t i = 0; i < max; i++)
		for (size_t j = 1; j < max; j++)
			if (Tile::merge(positions[j-1][i], positions[j][i]))
				mergePossible = mergeSubOperation(i, j, j-1, i);
	return mergePossible;
}

bool Board::onDownArrowPressed()
{
	bool mergePossible = false;
	for (size_t i = 0; i < max; i++)
		for (int j = max - 2; j >= 0; j--)
			if (Tile::merge(positions[j+1][i], positions[j][i]))
				mergePossible = mergeSubOperation(i, j, j+1, i);

	return mergePossible;
}
