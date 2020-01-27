#include "GameLoop.h"



GameLoop::GameLoop(Interface inter):inter(inter)
{
	switch (inter)
	{
	case Console:
		board = new ConsoleBoard();
		break;
	case Graphic:
	// not implemented yet
		break;
	default:
		break;
	}
	//loop();
}


GameLoop::~GameLoop()
{
	delete board;
}

void GameLoop::loop()
{
	board->generateTile();
	board->generateTile();
	while (!board->isGameOver())
	{
		board->draw();
		listen();
		board->generateTile();
	}
}

void GameLoop::listen()
{
	Arrows arrow;
	bool possible = false;
	switch (inter)
	{
	case Console:
		listenConsole(arrow);
		break;
	case Graphic:
		break;
	default:
		break;
	}
	switch (arrow)
	{
	case Arrows::Left:
		while (board->onLeftArrowPressed())
		{
			possible = true;
			board->draw();
		}
		break;
	case  Arrows::Rigth:
		while (board->onRightArrowPressed())
		{
			possible = true;
			board->draw();
		}
		break;
	case  Arrows::Up:
		while (board->onUpArrowPressed())
		{
			possible = true;
			board->draw();
		}
		break;
	case  Arrows::Down:
		while (board->onDownArrowPressed())
		{
			possible = true;
			board->draw();
		}
		break;
	default:
		break;
	}
}

void GameLoop::listenConsole(Arrows& arrow)
{
	static DWORD cc;
	KEY_EVENT_RECORD krec;
	static HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
	static INPUT_RECORD irec;
	for (; ; )
	{
		ReadConsoleInput(console, &irec, 1, &cc);
		if (irec.EventType == KEY_EVENT
			&& ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
			)//&& ! ((KEY_EVENT_RECORD&)irec.Event).wRepeatCount )
		{
			krec = (KEY_EVENT_RECORD&)irec.Event; // up arrow wVirtualKeyCode 38, left arr = 37, right 39, down 40
			arrow = (Arrows) krec.wVirtualKeyCode;
			return;
		}
	}
}
