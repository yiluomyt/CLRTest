// usingTriangle.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "usingTriangle.h"

#using "../x64/Debug/triangle.dll"
using namespace TriangleNet;

USINGTRIANGLE_API std::list<std::array<float, 6>> getPoints(std::list<std::array<float, 2>> points)
{
	//将点添加到多边形中
	auto polygon = gcnew Geometry::Polygon();
	for (auto point : points)
	{
		polygon->Add(gcnew Geometry::Vertex(point[0], point[1]));
	}
	//设置三角剖分选项
	auto options = gcnew Meshing::ConstraintOptions();
	options->ConformingDelaunay = true;
	//设置三角剖分条件
	auto quality = gcnew Meshing::QualityOptions();
	quality->MaximumAngle = 100;
	quality->MinimumAngle = 30;
	//进行三角剖分
	auto mesh = Geometry::ExtensionMethods::Triangulate(polygon, options, quality);
	//将所生成的三角形顶点坐标分别保存为六元组
	std::list<std::array<float, 6>> pointsList;
	for each (auto triangle in mesh->Triangles)
	{
		std::array<float, 6> triPoints;
		for (int i = 0, count=0; i < 3; i++)
		{
			triPoints[count++] = triangle->GetVertex(i)->X;
			triPoints[count++] = triangle->GetVertex(i)->Y;
		}

		pointsList.push_back(triPoints);
	}

	std::cout << "DONE!" << std::endl;

	return pointsList;
}