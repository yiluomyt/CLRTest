#using "../x64/Debug/CSharpDLL.dll"//ʹ��#usingָ����Ҫ��/CLR����
#include<iostream>

using std::cout;
using std::endl;
int main()
{
	cout << "ʹ��C++����C#����" << endl;
	cout << "CMyAddClass:" << endl;
	//�����CSharpDLL::����C#�е����ƿռ�
	//�йܶ���ʹ��^��ʶ
	//�����йܶ���ʱ����Ҫʹ��gcnew�ؼ���
	CSharpDLL::CMyAddClass ^ addClass = gcnew CSharpDLL::CMyAddClass();
	//�ڵ����йܶ���ʱ��ʹ�÷���������ָ��
	addClass->num1 = 1;
	addClass->num2 = 2;
	cout << "The Result:";
	cout << addClass->AddFunc() << endl;
	system("pause");
	cout << "CMyWriteLine:" << endl;
	CSharpDLL::CMyWriteLine ^ writeClass = gcnew CSharpDLL::CMyWriteLine();
	writeClass->Text = "The Result.";
	writeClass->WriteLineFunc();
	system("pause");

	return 0;
}