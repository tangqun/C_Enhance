#include<iostream>

using namespace std;

class Test3
{
	// 尽量使用成员函数 实现运算符重载
	// 友元函数实现运算符重载是 左值 
	//friend Test3 operator-(Test3 &t2, Test3 &t1);

	friend ostream& operator<<(ostream &cout, Test3 &t1);
public:
	Test3();
	Test3(int x, int y);
	~Test3();

	void print()
	{
		cout << _x << " + " << _y << "i" << endl;
	}

	Test3 operator-(Test3 &t1)
	{
		Test3 t3(_x - t1._x, _y - t1._y);
		return t3;
	}

	Test3 operator+(Test3 &t1)
	{
		Test3 t3(_x + t1._x, _y + t1._y);
		return t3;
	}

	// 前置 ++
	Test3&  operator++()
	{
		this->_x++;
		this->_y++;
		return *this;
	}

	// 前置 --
	Test3&  operator--()
	{
		this->_x--;
		this->_y--;
		return *this;
	}

	// 后置 ++
	Test3  operator++(int)
	{
		Test3 tmp = *this;
		this->_x++;
		this->_y++;
		return tmp;
	}

	// 后置 --
	Test3  operator--(int)
	{
		Test3 tmp = *this;
		this->_x--;
		this->_y--;
		return tmp;
	}

	
private:
	int _x;
	int _y;
};

Test3::Test3()
{
}

Test3::Test3(int x, int y)
{
	_x = x;
	_y = y;
}

Test3::~Test3()
{
}

//Test3 operator-(Test3 &t2, Test3 &t1)
//{
//	Test3 t3(t2._x - t1._x, t2._y - t1._y);
//	return t3;
//}

// 无法使用成员函数实现 << 这个的重载， 因为无法在 ostream 里面添加
// ostream& operator<<(Test3 &t1)
ostream& operator<<(ostream &mycout, Test3 &t1)
{
	mycout << t1._x << " + " << t1._y << "i" << endl;
	return mycout;
}

void main03()
{
	Test3 t1(1, 2), t2(3, 4);
	t1.print();
	t2.print();

	Test3 t3 = t2 - t1;
	// 第一种 operator-(t2, t1)
	t3.print();

	Test3 t4 = t2 + t1;
	t4.print();

	++t2;
	t2.print();

	--t2;
	t2.print();

	t1++;
	t1.print();

	t1--;
	t1.print();

	cout << t1 << t2;
	// operator<<(cout, t1)

	system("pause");
}