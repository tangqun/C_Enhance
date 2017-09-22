#include<iostream>

using namespace std;

class A4
{
public:
	A4();
	A4(int x, int y);
	A4(const A4 & obj);
	~A4();

	int getX()
	{
		return _x;
	}
	int getY()
	{
		return _y;
	}
private:
	int _x;
	int _y;
};

A4::A4()
{
	cout << "���ù��캯�������Լ�" << endl;
}
A4::A4(int x, int y)
{
	_x = x;
	_y = y;
	cout << "���ù��캯�������Լ�" << endl;
}
A4::A4(const A4 & obj)
{
	_x = obj._x;
	_y = obj._y;
	cout << "���ù��캯����ͨ����һ������obj�����Լ�" << endl;
}

A4::~A4()
{
	cout << "�������������ͷ��Լ�" << endl;
}

A4 f()
{
	A4 a(1, 2);
	return a; // ���ش�������������
}

void mainObjDisplay()
{
	A4 a;		// ���ù��캯����������
	a = f();  // �������� = ��ֵ

	A4 b = f(); // ��57���б�������  ��ֵ���� �� �����ʼ��������
				// ������ù��캯������������ֱ��ת��Ϊ b ����

	A4 c = a;

	cout << "���Բ���" << endl;
}

void main08()
{
	mainObjDisplay();

	system("pause");
}