#include "ClockPanel.h"
#include <time.h>

ClockPanel::ClockPanel()
{
	// ��Ļ����
	this->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	// ����ʱ���������
	secondNum = gcnew Number(0);
	minuteNum = gcnew Number(1);
	hourNum = gcnew Number(2);

	this->addChild(secondNum);
	this->addChild(minuteNum);
	this->addChild(hourNum);

	// ˢ�±���ʱ��
	this->Flush();

	// ������ʱ����ÿ��ִ��һ�� Flush ����
	Timer::add(std::bind(&ClockPanel::Flush, this), 1.0f);
}

void ClockPanel::Flush()
{
	// ��ȡϵͳʱ��
	time_t nowtime;
	struct tm timeinfo;
	::time(&nowtime);
	::localtime_s(&timeinfo, &nowtime);
	// ��ȡʱ����
	int hour, min, sec;
	hour = timeinfo.tm_hour;
	min = timeinfo.tm_min;
	sec = timeinfo.tm_sec;

	// ˢ��ʱ��
	hourNum->setNumber(hour);
	minuteNum->setNumber(min);
	secondNum->setNumber(sec);

	// ��ת����
	if ((sec % 10) != 0)
	{
		// ������ת�Ƕ�
		float angle = (sec % 10) * 5 - 25;
		// ������ת����
		auto action = gcnew RotateTo(0.1f, angle);
		// ִ�ж���
		this->runAction(action);
	}
	else
	{
		// ���Ƕ���ת�� 20 ��
		this->setRotation(20);
		// ������ת������0.025 ����ʱ����ת 5 ��
		auto rotate = gcnew RotateBy(0.025f, -5);
		// �����ȴ��������ȴ� 0.025 ��
		auto delay = gcnew Delay(0.025f);
		// ������������ϳ���������
		auto seq = gcnew Sequence({ rotate, delay });
		// ����ѭ���������� two ����ѭ�� 9 ��
		auto loop = gcnew Loop(seq, 9);
		// ִ�ж���
		this->runAction(loop);
	}
}
