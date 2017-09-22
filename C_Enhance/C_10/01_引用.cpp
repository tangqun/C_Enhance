#include<iostream>

using namespace std;

int& f2()
{
	int a;
	a = 100;
	return a;
}
//
//int* f3()
//{
//	int a = 100;
//
//	return &a;
//}

void main()
{
	/*int a = 10;

	cout << "a: " << a << ", &a: " << &a << "\n";

	int a2 = f2();

	cout << "a2: " << a2 << ", &a2: " << &a2 << "\n";*/

	int &a3 = f2();

	cout << "a3: " << a3 << ", &a3: " << &a3 << "\n";

	system("pause");
}