//��ļ̳з�ʽ����������������Ӱ��

#include <cstdlib>
#include <iostream>

using namespace std;

/*
����Ȩ�ޣ�����
1�������������������ڲ� or �ⲿ
2����������δӸ���̳� public�� protected�� private
3��������ķ��ʼ���
*/
class A
{
private:
	int a;
protected:
	int b;
public:
	int c;

	A()
	{
		a = 0;		b = 0;		c = 0;
	}

	void set(int a, int b, int c)
	{
		this->a = a;		this->b = b;		this->c = c;
	}
};

class B : public A
{
public:
	void print()
	{
		//cout << "a = " << a; // err private
		cout << "b = " << b;
		cout << "c = " << endl;
	}
};

class C : protected A
{
public:
	void print()
	{
		//cout << "a = " << a; // err private
		cout << "b = " << b;
		cout << "c = " << endl;
	}
};

class D : private A
{
public:
	void print()
	{
		//cout << "a = " << a; // err private
		cout << "b = " << b;
		cout << "c = " << c << endl;
	}
};

int main01()
{

	A aa;
	B bb;
	C cc;
	D dd;

	aa.c = 100; // ok
	bb.c = 100; // ok
	//cc.c = 100; // err protected A
	//dd.c = 100; // err private A

	aa.set(1, 2, 3);	// ok
	bb.set(10, 20, 30); // ok
	//cc.set(40, 50, 60); // err protected A 
	//dd.set(70, 80, 90); // err private A

	bb.print(); // ok
	cc.print(); // ok
	dd.print();


	system("pause");
	return 0;
}
