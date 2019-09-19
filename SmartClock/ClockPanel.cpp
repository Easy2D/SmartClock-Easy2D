#include "ClockPanel.h"
#include <time.h>

ClockPanel::ClockPanel()
{
	// 屏幕居中
	this->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	// 创建时分秒的数字
	secondNum = gcnew Number(0);
	minuteNum = gcnew Number(1);
	hourNum = gcnew Number(2);

	this->addChild(secondNum);
	this->addChild(minuteNum);
	this->addChild(hourNum);

	// 刷新表盘时间
	this->Flush();

	// 创建定时器，每秒执行一次 Flush 函数
	Timer::add(std::bind(&ClockPanel::Flush, this), 1.0f);
}

void ClockPanel::Flush()
{
	// 获取系统时间
	time_t nowtime;
	struct tm timeinfo;
	::time(&nowtime);
	::localtime_s(&timeinfo, &nowtime);
	// 获取时分秒
	int hour, min, sec;
	hour = timeinfo.tm_hour;
	min = timeinfo.tm_min;
	sec = timeinfo.tm_sec;

	// 刷新时间
	hourNum->setNumber(hour);
	minuteNum->setNumber(min);
	secondNum->setNumber(sec);

	// 旋转表盘
	if ((sec % 10) != 0)
	{
		// 计算旋转角度
		float angle = (sec % 10) * 5 - 25;
		// 创建旋转动画
		auto action = gcnew RotateTo(0.1f, angle);
		// 执行动画
		this->runAction(action);
	}
	else
	{
		// 将角度旋转至 20 度
		this->setRotation(20);
		// 创建旋转动画，0.025 秒逆时针旋转 5 度
		auto rotate = gcnew RotateBy(0.025f, -5);
		// 创建等待动画，等待 0.025 秒
		auto delay = gcnew Delay(0.025f);
		// 将两个动画组合成连续动画
		auto seq = gcnew Sequence({ rotate, delay });
		// 创建循环动画，将 two 动画循环 9 次
		auto loop = gcnew Loop(seq, 9);
		// 执行动画
		this->runAction(loop);
	}
}
