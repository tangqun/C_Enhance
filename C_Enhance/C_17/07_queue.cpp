#include<iostream>
#include<queue>

using namespace std;

class A7
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

void printqueue(queue<A7> &q)
{
	while (!q.empty())
	{
		// 取第一个元素
		A7 a = q.front();
		cout << a.getA() << " ";
		q.pop();
	}
	cout << endl;
}

void main07()
{
	//queue<int> q1;

	A7 a1;
	A7 a2;
	A7 a3;

	a1.setA(30);
	a2.setA(31);
	a3.setA(32);

	queue<A7> q2;
	q2.push(a1);
	q2.push(a2);
	q2.push(a3);

	printqueue(q2);

	system("pause");
}