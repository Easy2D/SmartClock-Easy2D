#pragma once
#include <easy2d/easy2d.h>

using namespace easy2d;

class Number :
	public Node
{
public:
	Number(int mode);

	// ��������ģʽ��0 ������ӣ�1 ����������2 ����Сʱ��
	void setMode(int mode);
	// �������ִ�С
	void setNumber(int num);

protected:
	int mode;
};

