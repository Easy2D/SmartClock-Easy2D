#include "Number.h"
#include "resource.h"

Number::Number(int mode)
{
	this->setMode(mode);
}

void Number::setMode(int mode)
{
	this->mode = mode;

	switch (mode)
	{
	case 0:
	{
		this->setSkewY(-30);
		this->setRotation(-60);
		this->setScaleY(1.5f);
	}
	break;
	case 1:
	{
		this->setSkewY(30);
		this->setScaleY(1.33f);
	}
	break;
	case 2:
	{
		this->setSkewY(-30);
		this->setScaleY(1.33f);
	}
	break;
	default:
		break;
	}
}

void Number::setNumber(int num)
{
	this->removeAllChildren();

	int num1 = num / 10;
	int num2 = num % 10;

	float num1X = 24 * num1;
	float num1Y = 36 * mode;
	float num2X = 24 * num2;
	float num2Y = 36 * mode;

	auto num1Sprite = gcnew Sprite(IDB_PNG1, L"PNG", Rect(num1X, num1Y, 24, 36));
	auto num2Sprite = gcnew Sprite(IDB_PNG1, L"PNG", Rect(num2X, num2Y, 24, 36));

	this->addChild(num1Sprite);
	this->addChild(num2Sprite);

	switch (mode)
	{
	case 0:
	{
		num1Sprite->setAnchor(0, 1);
		num2Sprite->setAnchor(0, 1);

		num2Sprite->setPosX(24);
	}
	break;
	case 1:
	{
		num1Sprite->setAnchor(0, 0);
		num2Sprite->setAnchor(0, 0);

		num2Sprite->setPosX(24);
	}
	break;
	case 2:
	{
		num1Sprite->setAnchor(1, 0);
		num2Sprite->setAnchor(1, 0);

		num1Sprite->setPosX(-24);
	}
	break;
	}
}
