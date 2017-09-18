#include<iostream>

using namespace std;

void f1()
{
#define a 10
	const int b = 20;
//#undef a
}

void main()
{
	printf("a = %d, b = %d \n", a, 11);

	system("pause");
}