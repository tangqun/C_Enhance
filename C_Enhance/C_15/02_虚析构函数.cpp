#include<iostream>

using namespace std;

class Parent2
{
public:
	Parent2()
	{
		cout << "���๹�캯��" << endl;
	};
	virtual ~Parent2()
	{
		cout << "������������" << endl;
	};

private:

};

class Child2 : public Parent2
{
public:
	Child2()
	{
		cout << "���๹�캯��" << endl;
	};
	virtual ~Child2()
	{
		cout << "������������" << endl;
	};

private:

};

void playObj()
{
	
}

void main02()
{
	Parent2 *p = new Child2;

	delete p;

	system("pause");
}