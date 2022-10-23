//---------------------------------------------------------
// 程序名称：SmartClock
// 作者：Nomango
// 编译环境：Visual Studio 2019 / Easy2D v2.0.4
// 项目类型：Win32 Application
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
		// 设置窗口图标
		Window::setIcon(IDI_ICON1);

		// 添加资源路径
		Path::add("res");

		// 创建一个空场景
		auto scene = gcnew Scene;
		SceneManager::enter(scene);

		// 创建一个表盘
		auto panel = gcnew ClockPanel;
		scene->addChild(panel);

		Game::start();
	}
	Game::destroy();
	return 0;
}