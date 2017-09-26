#include<iostream>

using namespace std;

int add(int i, int j)
{
	return i + j;
}

int subtract(int i, int j)
{
	return i - j;
}

int multiply(int i, int j)
{
	return i * j;
}

int divide(int i, int j)
{
	return i / j;
}

int playObj(int(*FuncType)(int, int))
{
	return FuncType(12, 4);
}

void main()
{
	cout << playObj(add) << endl; 

	cout << playObj(subtract) << endl;

	cout << playObj(multiply) << endl;

	cout << playObj(divide) << endl;

	system("pause");
}