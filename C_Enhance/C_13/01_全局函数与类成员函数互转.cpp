#include<iostream>

using namespace std;

class Test1
{
public:
	Test1(int x, int y)
	{
		_x = x;
		_y = y;
	};
	~Test1()
	{

	};

	int getX()
	{
		return _x;
	}

	int getY()
	{
		return _y;
	}

	Test1& add(Test1& t2)
	{
		this->_x = this->_x + t2.getX();
		this->_y = this->_y + t2.getY();
		return *this;
	}

	Test1 add2(Test1& t2)
	{
		// 返回匿名对象
		Test1 t3(this->_x + t2.getX(), this->_y + t2.getY());
		return t3;
	}

	void printAB()
	{
		cout << "x: " << this->_x << ", y: " << this->_y << endl;
	}

private:
	int _x;
	int _y;
};

Test1 add(Test1& t1, Test1& t2)
{
	Test1 t3(t1 .getX()+ t2.getX(), t1.getY() + t2.getY());
	return t3;
}

void printAB(Test1& t1)
{
	cout << "x: " << t1.getX() << ", y: " << t1.getY() << endl;
}

void main01()
{
	Test1 t1(1, 2);
	Test1 t2(3, 4);

	t1.add(t2);

	t1.printAB();

	system("pause");
}