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
		cout << "���Ǹ��ຯ��" << endl;
	}

	virtual void print(int i)
	{
		cout << "���Ǹ����麯��" << endl;
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
		cout << "���������麯��" << endl;
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