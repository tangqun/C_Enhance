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
	cout << "���ù��캯�������Լ�" << endl;
}
A2::A2(const A2 & obj)
{
	cout << "���ù��캯����ͨ����һ������obj�����Լ�" << endl;
}

A2::~A2()
{
	cout << "�������������ͷ��Լ�" << endl;
}

void main06()
{
	A2 a;
	A2 a2(a);

	system("pause");
}