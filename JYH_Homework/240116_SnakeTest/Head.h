#pragma once
#include "Part.h"

class Head : public Part
{
public:
	Head();

protected:
	void Update() override;

private:
	int PrevMove = 0;
};

