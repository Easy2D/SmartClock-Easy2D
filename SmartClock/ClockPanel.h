#pragma once
#include <easy2d.h>
#include "Number.h"

using namespace easy2d;

class ClockPanel :
	public Node
{
public:
	ClockPanel();

	// Ë¢ÐÂÊ±¼ä
	void Flush();

protected:
	Number * secondNum;
	Number * minuteNum;
	Number * hourNum;
};

