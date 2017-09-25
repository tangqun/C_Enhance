#include<iostream>

using namespace std;

class Parent2
{
public:
	Parent2()
	{
		cout << "父类构造函数" << endl;
	};
	virtual ~Parent2()
	{
		cout << "父类析构函数" << endl;
	};

private:

};

class Child2 : public Parent2
{
public:
	Child2()
	{
		cout << "子类构造函数" << endl;
	};
	virtual ~Child2()
	{
		cout << "子类析构函数" << endl;
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