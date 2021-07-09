#pragma once
#include"graphics.h"


struct mouseData
{
	int x;
	int y;
};

class Mouse_Event {
public:
	mouseData clickEventHandling();
};