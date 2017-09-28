#include<iostream>

using namespace std;

template<typename T>
class A
{
public:
	A(T a)
	{
		this->_a = a;
	};
	~A()
	{

	};

	T getA()
	{
		return this->_a;
	}
	void setA(T a)
	{
		this->_a = a;
	}

private:
	T _a;
};

class B
{
public:
	B()
	{

	};
	~B()
	{

	};

private:

};

class C : public A<int>
{
public:
	C(int c, int a) : A(a)
	{
		this->_c = c;
	}

private:
	int _c;
};

void printC(C *c)
{
	cout << c->getA() << endl;
}

void main01()
{
	C c(1, 2);

	printC(&c);

	system("pause");
}