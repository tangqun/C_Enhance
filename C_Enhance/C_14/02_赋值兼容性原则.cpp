#include<iostream>

using namespace std;

/*
1、子类对象可以当作父类对象使用		
2、子类对象可以直接赋值给父类对象	
3、子类对象可以直接初始化父类对象	
4、父类指针可以直接指向子类对象		
5、父类引用可以直接引用子类对象		
*/
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