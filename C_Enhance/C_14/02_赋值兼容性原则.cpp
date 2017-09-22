#include<iostream>

using namespace std;

class Parent
{
public:
	Parent()
	{

	};
	~Parent()
	{

	};

	void print()
	{
		cout << a << ", " << b << endl;
	}

protected:
	int a;
	int b;

private:

};

class Child : public Parent
{
public:
	Child()
	{
		a = 1, b = 2, c = 3;
	};
	~Child()
	{

	};

	void print()
	{
		cout << a << ", " << b << ", " << c << endl;
	}

private:
	int c;
};

void main02()
{
	Parent p;
	p.print();

	Child c;
	c.print();

	p = c;			// 1、子类直接赋值给父类对象
	p.print();

	Parent p2 = c;	// 2、通过子类初始化父类对象
	p2.print();

	Parent *p3 = &c;// 3、父亲指针可以直接指向子类对象
	p3->print();

	Parent &p4 = c;	// 4、父类引用可以直接引用子类对象
	p4.print();

	system("pause");
}