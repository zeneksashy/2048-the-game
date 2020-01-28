#pragma once
#include"ConsoleBoard.h"
enum Interface
{
	Console, Graphic
};
enum class Arrows
{
	Left = 37, Rigth = 39, Up = 38, Down = 40
};

class GameLoop
{
public:
	GameLoop(Interface);
	~GameLoop();
	void loop();
private:
	Board * board;
	Interface inter;
	void listen();
	void listenConsole(Arrows& arrow);

};

