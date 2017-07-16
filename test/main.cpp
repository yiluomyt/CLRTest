#include<Windows.h>//用于加载DLL
#include<iostream>
#include<fstream>
#include<vector>
#include<array>
#include<list>

//加载生成DLL时同时生成的静态链接库
#pragma comment(lib, "../x64/Debug/usingTriangle.lib")
//包含导出函数的头文件
#include"../usingTriangle/usingTriangle.h"

using namespace std;

typedef struct MyPoint
{
	float _x, _y;

	MyPoint() { _x = 0; _y = 0; }
	MyPoint(float x, float y) { _x = x; _y = y; }

	operator array<float, 2>() { return array<float, 2>{_x, _y}; }
};

int main()
{
	cout<< "test" << endl;
	//加载DLL
	HMODULE hMoudle = LoadLibrary(L"usingTriangle.dll");
	if (!hMoudle)
	{
		cerr << "Can't open the dll." << endl;
	}

	list<array<float, 2>> pl;
	pl.push_back(MyPoint(0, 0));
	pl.push_back(MyPoint(500, 0));
	pl.push_back(MyPoint(0, 500));
	pl.push_back(MyPoint(500, 500));
	pl.push_back(MyPoint(1000, 0));
	pl.push_back(MyPoint(1000, 500));

	
	ofstream fout;
	fout.open("M:/t.node");
	int count = 0;
	auto pointsList = getPoints(pl);
	fout << pointsList.size() * 3 << endl;
	for (auto points : pointsList)
	{
		fout << count << " " << points[0] << " " << points[1] << endl;
		count++;

		fout << count << " " << points[2] << " " << points[3] << endl;
		count++;

		fout << count << " " << points[4] << " " << points[5] << endl;
		count++;
	}
	fout.close();
	//释放DLL
	FreeLibrary(hMoudle);
	
	system("pause");
	return 0;
}