#include<iostream>

using namespace std;

class A10
{
public:
	A10(int x)
	{
		_x = x;
	};
	~A10()
	{

	};

private:
	int _x;
};

class B10
{
public:
	// ��Ա�����ĳ�ʼ��˳��������˳���й�
	B10(int x) :_a(x), _a2(x)
	{

	};
	~B10()
	{

	};

private:
	int _x;
	A10 _a;
	A10 _a2;
};

void main10()
{
	B10 b(10);

	system("pause");
}