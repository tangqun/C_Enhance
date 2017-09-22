#include<iostream>

using namespace std;

class Parent4
{
public:
	static int a;
	int b;

protected:
	
private:

};

int Parent4::a = 10;

class Child4 : private Parent4
{
public:

	void print()
	{
		cout << a << endl;
	}

private:
	
};

void main04()
{
	Child4 c;

	c.print();
	//c.a;
}