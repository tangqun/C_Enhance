#include<iostream>

using namespace std;

int func(int i)
{
	return i;
}

void main01()
{
	{
		//int array1[10];
		typedef int(ArrayType)[10];
		ArrayType arrayType;
		arrayType[0] = 1;
	}

	{
		int array2[10];
		typedef int(*PArrayType)[10];
		PArrayType pArrayType;
		pArrayType = &array2;
		(*pArrayType)[0] = 2; // (*pArrayType)[0]  *pArrayType[0]  Ч����ͬ 
		cout << array2[0] << endl;
	}

	typedef int(FuncType)(int);
	FuncType *funcType;
	{
		funcType = func;
		cout << funcType(10) << endl;
	}

	{
		funcType = &func;
		cout << funcType(100) << endl;
	}

	typedef int(*PFuncType)(int);
	PFuncType pFuncType; 

	{
		pFuncType = func;				// ���������Ǻ������׵�ַ &������Ч��Ҳ��ȡ�������׵�ַ
		cout << pFuncType(20) << endl;
	}

	{
		pFuncType = &func;				// ���������Ǻ������׵�ַ &������Ч��Ҳ��ȡ�������׵�ַ  ��ʷ��������
		cout << pFuncType(200) << endl;
	}

	system("pause");
}