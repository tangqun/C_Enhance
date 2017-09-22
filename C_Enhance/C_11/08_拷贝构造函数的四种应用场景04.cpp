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
	return a; // 返回创建的匿名对象
}

void mainObjDisplay()
{
	A4 a;		// 调用构造函数创建对象
	a = f();  // 匿名对象 = 赋值

	A4 b = f(); // 与57行有本质区别  赋值操作 和 对象初始化操作，
				// 不会调用构造函数，匿名对象直接转化为 b 对象

	A4 c = a;

	cout << "测试测试" << endl;
}

void main08()
{
	mainObjDisplay();

	system("pause");
}