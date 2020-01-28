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
	char c;
	bool want_to_play = false;


	do
	{
		GameLoop loop(Interface::Console);
		loop.loop();
		std::cout << "\nDo you want to play again ? press Y if yes\n";
		std::cin >> c;
		switch (c)
		{
		case 'Y':
		case 'y':
			want_to_play = true;
			break;
		default:
			want_to_play = false;
			break;

		}
	} while (want_to_play);
	
}