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
	cout << "调用构造函数创建自己" << endl;
}
A4::A4(int x, int y)
{
	_x = x;
	_y = y;
	cout << "调用构造函数创建自己" << endl;
}
A4::A4(const A4 & obj)
{
	_x = obj._x;
	_y = obj._y;
	cout << "调用构造函数，通过另一个对象obj创建自己" << endl;
}

A4::~A4()
{
	cout << "调用析构函数释放自己" << endl;
}

A4 f()
{
	A4 a(1, 2);
	return a;
}

void main()
{
	A4 b;
	b = f();

	//system("pause");
}