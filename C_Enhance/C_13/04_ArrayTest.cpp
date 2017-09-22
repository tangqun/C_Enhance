#include<iostream>
#include "Array.h"

using namespace std;

void main04()
{
	Array a1(10);

	for (int i = 0; i < a1.length(); i++)
	{
		a1[i] = i;
	}

	for (int i = 0; i < a1.length(); i++)
	{
		cout << "array " << i << ": " << a1[i] << endl;
	}

	Array a2 = a1;

	for (int i = 0; i < a2.length(); i++)
	{
		cout << "array " << i << ": " << a2[i] << endl;
	}

	Array a3(20);
	a2 = a3 = a1;

	if (a1 == a2)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	if (a1 != a2)
	{
		cout << "不相等" << endl;
	}
	else
	{
		cout << "相等" << endl;
	}

	system("pause");
}