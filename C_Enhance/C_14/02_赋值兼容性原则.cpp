#include<iostream>

using namespace std;

/*
1�����������Ե����������ʹ��		
2������������ֱ�Ӹ�ֵ���������	
3������������ֱ�ӳ�ʼ���������	
4������ָ�����ֱ��ָ���������		
5���������ÿ���ֱ�������������		
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

	p = c;			// 1������ֱ�Ӹ�ֵ���������
	p.print();

	Parent p2 = c;	// 2��ͨ�������ʼ���������
	p2.print();

	Parent *p3 = &c;// 3������ָ�����ֱ��ָ���������
	p3->print();

	Parent &p4 = c;	// 4���������ÿ���ֱ�������������
	p4.print();

	system("pause");
}