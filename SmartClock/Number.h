#pragma once
#include <easy2d/easy2d.h>

using namespace easy2d;

class Number :
	public Node
{
public:
	Number(int mode);

	// 设置数字模式，0 代表分钟，1 代表秒数，2 代表小时数
	void setMode(int mode);
	// 设置数字大小
	void setNumber(int num);

protected:
	int mode;
};

