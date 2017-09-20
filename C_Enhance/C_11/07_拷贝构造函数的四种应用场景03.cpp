#include<iostream>

using namespace std;

class A3
{
public:
	A3(int x, int y);
	A3(const A3 & obj);
	~A3();
	
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

A3::A3(int x, int y)
{
	_x = x;
	_y = y;
	cout << "���ù��캯�������Լ�" << endl;
}
A3::A3(const A3 & obj)
{
	_x = obj._x;
	_y = obj._y;
	cout << "���ù��캯����ͨ����һ������obj�����Լ�" << endl;
}

A3::~A3()
{
	cout << "�������������ͷ��Լ�" << endl;
}

void f(A3 p)
{
	cout << "Function: " << p.getX() << ", " << p.getY() << endl;
}

void main07()
{
	A3 a(1, 2);
	f(a);

	//system("pause");
}