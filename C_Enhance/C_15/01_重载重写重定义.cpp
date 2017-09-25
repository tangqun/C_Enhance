#include<iostream>

using namespace std;

class A
{
public:
	A()
	{
		print(10);
	};
	~A()
	{

	};

	void print()
	{
		cout << "父类print函数" << endl;
	}

	virtual void print(int i)
	{
		cout << "父类print虚函数" << endl;
	}

	void print(int i, int j)
	{
		cout << "父类print函数，子类没有" << endl;
	}

private:

};

class B : public A
{
public:
	B()
	{

	};
	~B()
	{

	};

	void print()
	{
		cout << "子类print函数" << endl;
	}

	void print(int i)
	{
		cout << "子类print重写函数" << endl;
	}

private:

};

void main01()
{
	//A *a = new B;
	//a->print();
	//a->print(10);

	//B *b = new B;
	//b->print(); 
	//b->print(10);
	//b->A::print(10, 20); // c#支持直接访问

	B *b2 = new B;
	
	
	system("pause");
}