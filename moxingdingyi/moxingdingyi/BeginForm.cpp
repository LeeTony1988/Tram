#include "BeginForm.h"

// moxingdingyi.cpp: ����Ŀ�ļ���

using namespace moxingdingyi;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false);

	// ���������ڲ�������
	Application::Run(gcnew BeginForm());
	return 0;
}