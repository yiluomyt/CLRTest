// usingTriangle.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "usingTriangle.h"

#using "../x64/Debug/triangle.dll"
using namespace TriangleNet;

USINGTRIANGLE_API std::list<std::array<float, 6>> getPoints(std::list<std::array<float, 2>> points)
{
	//������ӵ��������
	auto polygon = gcnew Geometry::Polygon();
	for (auto point : points)
	{
		polygon->Add(gcnew Geometry::Vertex(point[0], point[1]));
	}
	//���������ʷ�ѡ��
	auto options = gcnew Meshing::ConstraintOptions();
	options->ConformingDelaunay = true;
	//���������ʷ�����
	auto quality = gcnew Meshing::QualityOptions();
	quality->MaximumAngle = 100;
	quality->MinimumAngle = 30;
	//���������ʷ�
	auto mesh = Geometry::ExtensionMethods::Triangulate(polygon, options, quality);
	//�������ɵ������ζ�������ֱ𱣴�Ϊ��Ԫ��
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