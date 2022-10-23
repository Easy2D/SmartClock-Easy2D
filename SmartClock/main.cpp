//---------------------------------------------------------
// �������ƣ�SmartClock
// ���ߣ�Nomango
// ���뻷����Visual Studio 2019 / Easy2D v2.0.4
// ��Ŀ���ͣ�Win32 Application
//---------------------------------------------------------

#include <easy2d/easy2d.h>
#include "resource.h"
#include "ClockPanel.h"

using namespace easy2d;

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	if (Game::init("SmartClock", 300, 300))
	{
		// ���ô���ͼ��
		Window::setIcon(IDI_ICON1);

		// �����Դ·��
		Path::add("res");

		// ����һ���ճ���
		auto scene = gcnew Scene;
		SceneManager::enter(scene);

		// ����һ������
		auto panel = gcnew ClockPanel;
		scene->addChild(panel);

		Game::start();
	}
	Game::destroy();
	return 0;
}