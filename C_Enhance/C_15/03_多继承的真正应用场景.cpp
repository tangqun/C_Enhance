#include<iostream>

using namespace std;

class Interface1
{
public:
	virtual int add(int i, int j) = 0;

private:

};

class Parent3
{
public:
	Parent3()
	{

	};
	~Parent3()
	{

	};

private:

};

class Child3 : public Parent3, public Interface1
{
public:
	Child3()
	{

	};
	~Child3()
	{

	};

	virtual int add(int i, int j)
	{
		return i + j;
	}

private:

};

void main03()
{
	Interface1 *p = new Child3;
	cout << p->add(10, 20) << endl;

	system("pause");
}