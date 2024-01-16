#pragma once
#include <vector>
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
	int2 PrevPos = {};

private:
};

