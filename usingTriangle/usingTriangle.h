// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� USINGTRIANGLE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// USINGTRIANGLE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef USINGTRIANGLE_EXPORTS
#define USINGTRIANGLE_API __declspec(dllexport)
#else
#define USINGTRIANGLE_API __declspec(dllimport)
#endif

USINGTRIANGLE_API std::list<std::array<float, 6>> getPoints(std::list<std::array<float, 2>>);