#using "../Debug/CSharpDLL.dll"
#include<iostream>

using std::cout;
using std::endl;
int main()
{
	cout << "使用C++调用C#代码" << endl;
	cout << "CMyAddClass:" << endl;
	CSharpDLL::CMyAddClass ^ addClass = gcnew CSharpDLL::CMyAddClass();
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