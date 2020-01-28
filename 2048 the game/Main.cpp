#include"includes.h"
#include<Windows.h>
#include"initializers.h"
#include "Tile.h"
#include<random>
#include"ConsoleBoard.h"
#include"GameLoop.h"
std::vector<Tile> tiles;

int main()
{

	/*for (size_t i = 0; i < 5; i++)
	{
		std::cout << randomize() << '\n';
	}*/
	auto sm = __cplusplus;

	GameLoop loop(Interface::Console);
	loop.loop();
	//std::cout << "hello world\n";
	//std::cin.get(input,1);
	//std::cout << input;
}