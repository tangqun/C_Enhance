#include<iostream>

using namespace std;

class Object3
{
public:
	Object3(const char *p)
	{

	};
	~Object3()
	{

	};

	int d;
private:

};

class Parent3 : public Object3
{
public:
	Parent3(int _a, int _b, const char *p) : Object3(p)
	{
		a = _a;
		b = _b;
	};
	~Parent3()
	{

	};

	void print()
	{
		cout << a << ", " << b << endl;
	}

	int d;
protected:
	int a;
	int b;

private:

};

class Child3 : public Parent3
{
public:
	Child3(const char *p) : Parent3(1, 2, p)
	{
		c = 3;
	};
	~Child3()
	{

	};

	void print()
	{
		cout << a << ", " << b << ", " << c << endl;
	}

	int d;
private:
	int c;
};

void main03()
{
	const char *p = "บวบว";

	Child3 c(p);

	c.Parent3::d = 10;

	c.Object3::d = 11;
}