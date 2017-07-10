#using "../Triangle/bin/Debug/Triangle.dll"
#include<iostream>

using namespace std;
using namespace TriangleNet;

int main()
{
	cout << "test" << endl;
	auto polygon = IO::FileProcessor::Read("C:\\Users\\mytyi\\Desktop\\Í¼ÐÎÈý½Ç»¯\\0701\\points.node");

	auto options = gcnew Meshing::ConstraintOptions();
	options->ConformingDelaunay = true;

	auto quality = gcnew Meshing::QualityOptions();
	quality->MaximumAngle = 100;
	quality->MinimumAngle = 30;

	auto mesh = Geometry::ExtensionMethods::Triangulate(polygon, options, quality);
	for each (auto trianlge in mesh->Triangles)
	{
		cout << trianlge->GetVertex(0)->X << endl;
	}

	system("pause");
	return 0;
}