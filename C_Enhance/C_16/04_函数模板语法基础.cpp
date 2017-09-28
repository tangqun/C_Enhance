#include<iostream>

using namespace std;

template <typename T>
void myswap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

void main04()
{
	int a = 1, b = 2;
	myswap(a, b);
	cout << "a: " << a << ", b: " << b << endl;

	myswap<int>(a, b);
	cout << "a: " << a << ", b: " << b << endl;

	system("pause");
}