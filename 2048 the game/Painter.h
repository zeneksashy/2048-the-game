#pragma once
#include "includes.h"
class Painter
{
public:
	Painter();
	~Painter();
	virtual void draw() = 0;
	virtual void showMessage(const std::string & msg) = 0;
};

