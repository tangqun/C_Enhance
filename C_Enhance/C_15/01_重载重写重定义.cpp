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
		cout << "����print����" << endl;
	}

	virtual void print(int i)
	{
		cout << "����print�麯��" << endl;
	}

	void print(int i, int j)
	{
		cout << "����print����������û��" << endl;
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
		cout << "����print����" << endl;
	}

	void print(int i)
	{
		cout << "����print��д����" << endl;
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
	//b->A::print(10, 20); // c#֧��ֱ�ӷ���

	B *b2 = new B;
	
	
	system("pause");
}