#include<iostream>

using namespace std;

class A
{
public:
	A()
	{

	};
	~A()
	{

	};

	void print()
	{
		cout << "这是父类函数" << endl;
	}

	virtual void print(int i)
	{
		cout << "这是父类虚函数" << endl;
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

	void print(int i)
	{
		cout << "这是子类虚函数" << endl;
	}

private:

};

void main()
{
	A *a = new B;
	a->print();

	B *b = new B;
	b->A::print();
	

	system("pause");
}