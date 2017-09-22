#include<iostream>

using namespace std;

class A12
{
public:
	A12()
	{

	};
	~A12()
	{

	};

	static int getC()
	{
		return _c;
	}

	static void setC(int c)
	{
		_c = c;
	}

private:
	int _a;
	int _b;
	static int _c;
};
int A12::_c = 0;

void main12()
{
	A12 *a = new A12();
	A12 *b = new A12();

	cout << b->getC() << endl;

	a->setC(100);
	
	cout << b->getC() << endl;

	cout << A12::getC() << endl;

	system("pause");
}