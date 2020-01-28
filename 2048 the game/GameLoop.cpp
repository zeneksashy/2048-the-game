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
	while (true)
	{
		board->draw();
		listen();
		if (board->isGameOver())
			break;
		board->generateTile();
	}
	if (board->hasWin())
		board->showMessage("You Won");
	else
		board->showMessage("You Lose");
}

void GameLoop::listen()
{
	Arrows arrow;
	bool moved = false;
	switch (inter)
	{
	case Console:
		listenConsole(arrow);
		break;
	case Graphic:
		break;
	default:
		throw std::invalid_argument("Only Console or Graphic version supported");
		break;
	}
	switch (arrow)
	{
	case Arrows::Left:
		while (board->onLeftArrowPressed())
		{
			moved = true;
			board->draw();
		}
		break;
	case  Arrows::Rigth:
		while (board->onRightArrowPressed())
		{
			moved = true;
			board->draw();
		}
		break;
	case  Arrows::Up:
		while (board->onUpArrowPressed())
		{
			moved = true;
			board->draw();
		}
		break;
	case  Arrows::Down:
		while (board->onDownArrowPressed())
		{
			moved = true;
			board->draw();
		}
		break;
	default:
		//board->showMessage("Only arrows alowed");
		listen();
		break;
	}
	if (!moved)
	{
		if (board->onDownArrowPressed(false) || board->onUpArrowPressed(false) || board->onLeftArrowPressed(false) || board->onRightArrowPressed(false))
			listen();
		else
			board->lose();
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
