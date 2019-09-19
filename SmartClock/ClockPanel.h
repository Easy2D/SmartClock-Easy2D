#pragma once
#include <easy2d.h>
#include "Number.h"

using namespace easy2d;

class ClockPanel :
	public Node
{
public:
	ClockPanel();

	// ˢ��ʱ��
	void Flush();

protected:
	Number * secondNum;
	Number * minuteNum;
	Number * hourNum;
};

