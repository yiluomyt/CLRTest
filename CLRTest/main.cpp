#using "../x64/Debug/CSharpDLL.dll"//使用#using指令需要打开/CLR开关
#include<iostream>

using std::cout;
using std::endl;
int main()
{
	cout << "使用C++调用C#代码" << endl;
	cout << "CMyAddClass:" << endl;
	//这里的CSharpDLL::是在C#中的名称空间
	//托管对象使用^标识
	//创建托管对象时，需要使用gcnew关键词
	CSharpDLL::CMyAddClass ^ addClass = gcnew CSharpDLL::CMyAddClass();
	//在调用托管对象时，使用方法类似于指针
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