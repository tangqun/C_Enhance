#include<iostream>

using namespace std;

class A2
{
public:
	A2();
	A2(const A2 & obj);
	~A2();

private:

};

A2::A2()
{
	cout << "调用构造函数创建自己" << endl;
}
A2::A2(const A2 & obj)
{
	cout << "调用构造函数，通过另一个对象obj创建自己" << endl;
}

A2::~A2()
{
	cout << "调用析构函数释放自己" << endl;
}

void main06()
{
	A2 a;
	A2 a2(a);

	system("pause");
}