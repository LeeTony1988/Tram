#include "BeginForm.h"

// moxingdingyi.cpp: 主项目文件。

using namespace moxingdingyi;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// 在创建任何控件之前启用 Windows XP 可视化效果
	Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false);

	// 创建主窗口并运行它
	Application::Run(gcnew BeginForm());
	return 0;
}