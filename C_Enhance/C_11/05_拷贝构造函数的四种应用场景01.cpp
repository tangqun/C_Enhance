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
	cout << "���ù��캯�������Լ�" << endl;
}
A::A(const A & obj)
{
	cout << "���ù��캯����ͨ����һ������obj�����Լ�" << endl;
}

A::~A()
{
	cout << "�������������ͷ��Լ�" << endl;
}

void main05()
{
	A a;
	A a2 = a; 

	system("pause");
}