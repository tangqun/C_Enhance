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
	cout << "调用构造函数创建自己" << endl;
}
A3::A3(const A3 & obj)
{
	_x = obj._x;
	_y = obj._y;
	cout << "调用构造函数，通过另一个对象obj创建自己" << endl;
}

A3::~A3()
{
	cout << "调用析构函数释放自己" << endl;
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