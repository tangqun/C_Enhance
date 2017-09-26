#include<iostream>

using namespace std;

int func(int i)
{
	return i;
}

void main01()
{
	int arr[10];
	typedef int(ArrayType)[10];

	ArrayType *arrayType = &arr;
	(*arrayType)[0] = 1; // (*arrayType)[0]  *arrayType[0]
	cout << arr[0] << endl;

	typedef int(FuncType)(int);
	FuncType *funcType = func;
	cout << funcType(10) << endl;

	typedef int(*PArrayType)[10];
	PArrayType pArrayType = &arr;
	(*pArrayType)[0] = 2; // (*pArrayType)[0]  *pArrayType[0]  效果等同 
	cout << arr[0] << endl;

	typedef int(*PFuncType)(int);
	PFuncType pFuncType = &func; // 函数名就是函数的首地址 &函数名效果也是取函数的首地址
	cout << pFuncType(20) << endl;

	system("pause");
}