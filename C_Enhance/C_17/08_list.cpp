#include<iostream>
#include<list>

using namespace std;

void testfor()
{
	//1��i = 0  ��ʼ����ֵ
	//2��i<10 �����ж�, �������Ϊ��, �����ִ��
	//3��ִ��ѭ�������
	//4��i++ ����i����
	//5���ص���2��, һֱѭ����ȥ, ֱ����2��Ϊ��, �˳�ѭ��.

	const int arraysize = 10;
	int ai[arraysize] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *begin = ai;
	int *end = ai + arraysize;

	int *pi = NULL;
	for (pi = begin; pi != end; pi++) // pi++ �� ++piЧ����ͬ
	{
		cout << *pi << " ";
	}
}

class A8
{
public:
	void setA(int a)
	{
		this->_a = a;
	}
	int getA()
	{
		return this->_a;
	}

private:
	int _a;
};

void printlist(list<A8> &lt)
{
	for (list<A8>::iterator p = lt.begin(); p != lt.end(); p++)
	{
		cout << p->getA() << " ";
	}
	cout << endl;
}

void printlist(list<A8 *> &lt)
{
	for (list<A8 *>::iterator p = lt.begin(); p != lt.end(); p++)
	{
		// ����ָ��
		cout << (*p)->getA() << " ";
	}
	cout << endl;
}

void main()
{
	list<A8 *> list1;

	A8 a1;
	A8 a2;
	A8 a3;
	A8 a4;
	A8 a5;
	A8 a6;

	a1.setA(11);
	a2.setA(12);
	a3.setA(13);
	a4.setA(14);
	a5.setA(15);
	a6.setA(100);

	list1.push_back(&a1);
	list1.push_back(&a2);
	list1.push_back(&a3);
	list1.push_back(&a4);
	list1.push_back(&a5);

	printlist(list1);

	list<A8 *>::iterator cur = list1.begin();
	cur++;
	cur++;
	cur++;

	list1.insert(cur, &a6);

	printlist(list1);

	system("pause");
}

void main08_1()
{
	list<A8> list1;

	A8 a1;
	A8 a2;
	A8 a3;
	A8 a4;
	A8 a5;
	A8 a6;

	a1.setA(11);
	a2.setA(12);
	a3.setA(13);
	a4.setA(14);
	a5.setA(15);
	a6.setA(100);

	list1.push_back(a1);
	list1.push_back(a2);
	list1.push_back(a3);
	list1.push_back(a4);
	list1.push_back(a5);

	printlist(list1);

	list<A8>::iterator cur = list1.begin();
	cur++;
	cur++;
	cur++;

	list1.insert(cur, a6);

	printlist(list1);

	system("pause");
}