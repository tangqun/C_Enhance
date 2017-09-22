#include<iostream>

using namespace std;

class Test3
{
	// ����ʹ�ó�Ա���� ʵ�����������
	// ��Ԫ����ʵ������������� ��ֵ 
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

	// ǰ�� ++
	Test3&  operator++()
	{
		this->_x++;
		this->_y++;
		return *this;
	}

	// ǰ�� --
	Test3&  operator--()
	{
		this->_x--;
		this->_y--;
		return *this;
	}

	// ���� ++
	Test3  operator++(int)
	{
		Test3 tmp = *this;
		this->_x++;
		this->_y++;
		return tmp;
	}

	// ���� --
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

// �޷�ʹ�ó�Ա����ʵ�� << ��������أ� ��Ϊ�޷��� ostream �������
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
	// ��һ�� operator-(t2, t1)
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