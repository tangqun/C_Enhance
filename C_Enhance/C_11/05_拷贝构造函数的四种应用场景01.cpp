#include<iostream>

using namespace std;

class A
{
public:
	A();
	A(const A & obj);
	~A();

private:

};

A::A()
{
	cout << "调用构造函数创建自己" << endl;
}
A::A(const A & obj)
{
	cout << "调用构造函数，通过另一个对象obj创建自己" << endl;
}

A::~A()
{
	cout << "调用析构函数释放自己" << endl;
}

void main05()
{
	A a;
	A a2 = a; 

	system("pause");
}